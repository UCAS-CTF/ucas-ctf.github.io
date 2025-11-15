from Crypto.Util.number import bytes_to_long

def lfsr(seed, mask):
    output = (seed << 1) & 0xffffff
    i = (seed & mask) & 0xffffff
    lastbit = 0
    while i != 0:
        lastbit ^= (i & 1)
        i = i >> 1
    output ^= lastbit
    return (output, lastbit)

R = bytes_to_long(b"flagisflagisFlagIsflagflagFlag")
mask = 0b1010011000100011100

key = []
for i in range(30):
    tmp = 0
    for j in range(8):
        (R, out) = lfsr(R, mask)
        tmp = (tmp << 1) ^ out
    key.append(tmp)
key = bytes(key)
print(key)