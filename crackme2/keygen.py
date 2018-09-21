from random import randint

def sign_extend(x):
    b = bin(x)
    
    if len(b) == 10 and b[2] == '1':
        return x - 256

    else:
        return x

# the first 8 characters of the key are xor'd with these values
xor_vals = [0x45, 0x36, 0xab, 0xc8, 0xcc, 0x11, 0xe3, 0x7a]

# not guaranteed to make a good key the first time
while True:
    # the initial 8 values that determine the 9th value
    init_8 = [ randint(33, 126) for i in range(8) ]
    xor_8 = []
    
    for i in range(len(init_8)):
        xor_ch = init_8[i] ^ xor_vals[i]
        xor_8.append(xor_ch)
    
    xor_ext = [ sign_extend(x) for x in xor_8 ]
    xor_sum = sum(xor_ext)
    
    last_val = xor_sum & 0xff

    # last character needs to be lowercase
    if 97 <= last_val <= 122:
        key = ''.join([ chr(ch) for ch in init_8 + [last_val] ])
        print(key)
        break
