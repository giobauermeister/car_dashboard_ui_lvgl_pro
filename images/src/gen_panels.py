"""Side panels of screen_controls: images/panel_left.png and images/panel_right.png.

Measured on the reference video: a trapezoid whose long edge sits on the display side, sharp
tips there, rounded inner corners, a fill that gets lighter towards the inner edge, and a
hairline border all around. The border is brighter on the inner edges; on the display side
it is dimmer in the middle and brighter towards the tips.

    python3 images/src/gen_panels.py        (from the project root, next to project.xml)
"""
import math
import os
import numpy as np
from PIL import Image, ImageDraw, ImageFilter

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..")
W, H = 110, 680     # panel_w x panel_h of globals.xml
CUT = 87            # height of the slanted part at the top and the bottom
R = 52              # radius of the inner corners, fitted to the reference video (rms 0.3 px)
EDGE = 0.75         # the display-side edge sits this far in, so its border is drawn whole
LINE = 1.4          # border width
K = 4               # supersampling
PAD = 8             # room around the shape, so the border is not cut by the image edge


def fillet(p0, p1, p2, r, n=24):
    """Points of the arc that rounds the corner p1 of the path p0 -> p1 -> p2."""
    v0 = np.subtract(p0, p1); v2 = np.subtract(p2, p1)
    u0 = v0 / np.linalg.norm(v0); u2 = v2 / np.linalg.norm(v2)
    half = math.acos(float(np.clip(np.dot(u0, u2), -1, 1))) / 2
    d = r / math.tan(half)
    t0 = p1 + u0 * d
    bis = (u0 + u2) / np.linalg.norm(u0 + u2)
    c = p1 + bis * (r / math.sin(half))
    t2 = p1 + u2 * d
    a0 = math.atan2(t0[1] - c[1], t0[0] - c[0]); a2 = math.atan2(t2[1] - c[1], t2[0] - c[0])
    da = (a2 - a0 + math.pi) % (2 * math.pi) - math.pi
    return [(c[0] + r * math.cos(a0 + da * i / n), c[1] + r * math.sin(a0 + da * i / n)) for i in range(n + 1)]


def panel(path, mirror):
    """The left panel; the right one is its mirror image."""
    w, h = (W + 2 * PAD) * K, (H + 2 * PAD) * K
    ox, oy = PAD * K, PAD * K
    x0, x1 = ox + EDGE * K, ox + (W - 1) * K
    A, B, C, D = (x0, oy), (x1, oy + CUT * K), (x1, oy + (H - CUT) * K), (x0, oy + H * K - 1)
    pts = [A] + fillet(A, B, C, R * K) + fillet(B, C, D, R * K) + [D]
    m = Image.new("L", (w, h), 0)
    ImageDraw.Draw(m).polygon(pts, fill=255)
    inner = m.filter(ImageFilter.MinFilter(2 * int(LINE * K) + 1))
    mask = np.asarray(m, np.float32) / 255
    edge = mask - np.asarray(inner, np.float32) / 255

    yy, xx = np.mgrid[0:h, 0:w]
    fx = np.clip((xx - ox) / ((W - 1) * K), 0, 1)
    fy = np.clip((yy - oy) / ((H - 1) * K), 0, 1)
    tip = np.abs(fy - 0.5) * 2                      # 0 in the middle, 1 at the tips
    fill = np.stack([3 + 12 * fx, 4 + 14 * fx, 11 + 24 * fx], -1)
    line = np.array([60, 60, 76], np.float32) + ((1 - fx) ** 1.5)[..., None] * 85
    outer = xx < x0 + 3 * K                         # the border on the display side
    side = np.array([38, 40, 54], np.float32) + (tip ** 2)[..., None] * 80
    line = np.where(outer[..., None], side, line)
    rgb = fill * (1 - edge[..., None]) + line * edge[..., None]

    im = Image.fromarray(np.dstack([rgb, mask * 255]).clip(0, 255).astype(np.uint8), "RGBA")
    im = im.crop((ox, oy, ox + W * K, oy + H * K)).resize((W, H), Image.LANCZOS)
    if mirror:
        im = im.transpose(Image.FLIP_LEFT_RIGHT)
    im.save(path)


panel(os.path.join(ROOT, "images", "panel_left.png"), False)
panel(os.path.join(ROOT, "images", "panel_right.png"), True)
