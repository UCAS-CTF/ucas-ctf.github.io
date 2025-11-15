
import hashlib

h1 = hashlib.sha256(b"Hello World").hexdigest()
h2 = hashlib.sha256(b"Hello world").hexdigest()

print(f"Input 1: 'Hello World'")
print(f"Hash 1:  {h1}")
print(f"Input 2: 'Hello world'")
print(f"Hash 2:  {h2}")

# 计算汉明距离 (有多少位不同)
h1_bin = bin(int(h1, 16))[2:].zfill(256)
h2_bin = bin(int(h2, 16))[2:].zfill(256)

diff_bits = sum(b1 != b2 for b1, b2 in zip(h1_bin, h2_bin))
print(f"\nBits changed: {diff_bits} / 256")
print(f"Percentage:   {diff_bits / 256.0 * 100:.2f}%")