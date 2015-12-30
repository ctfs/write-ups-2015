import struct

from PIL import Image

def main():
    data = open("Fuzyll - The Alpha Molecule.wav", "rb").read()
    data = data[0x28:]

    dist = 10000
    for i in xrange(0, len(data)-4, dist):
        im = Image.new("RGB", (1024, 1024))
        for j in xrange(i, i + dist, 4):
            L, R = struct.unpack("<hh", data[i+j:i+j+4])
            x = 512 + L * 500 / 65536
            y = 512 + R * 500 / 65536
            im.putpixel((x,y), (255,255,255))
        im.save("test%08d.png" % i)
main()