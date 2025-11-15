from Crypto.Util.number import bytes_to_long

R, mask = bytes_to_long(b"flagisflagisFlagIsflagflagFlag"), 0b1010011000100011100

### LFSR1 ###

lfsr1 = lambda s, m: (((s << 1) & 0xffffff) | (lb := ((s & m) & 0xffffff).bit_count() & 1), lb)

key = []
for i in range(30):
    tmp = 0
    for j in range(8): tmp, R = (tmp << 1) | lfsr1(R, mask)[1], lfsr1(R, mask)[0]
    key.append(tmp)
print(bytes(key))

### LFSR2 ###
key = bytes([(tmp := 0, [((R := ((R << 1) & 0xffffff) ^ (out := ((R & mask) & 0xffffff).bit_count() & 1)), tmp := (tmp << 1) | out) for _ in range(8)], tmp)[-1] for _ in range(30)])
print(key)

### LFSR3 ###
class lfsr3():
    def __init__(self, init, mask, length):
        self.init = init
        self.mask = mask
        self.lengthmask = 2**(length+1) - 1

    def next(self):
        nextdata = (self.init << 1) & self.lengthmask 
        i = self.init & self.mask & self.lengthmask 
        output = 0
        while i != 0:
            output ^= (i & 1)
            i = i >> 1
        nextdata ^= output
        self.init = nextdata
        return output

print(bin(lfsr3(R, mask, 48).init))