#!/usr/bin/python3

# These are the field descriptions straight from bptc.txt
mode_descs = '''
^.^|  0     ^.^| M^1..0^, _G_~2~^4^, _B_~2~^4^, _B_~3~^4^, _R_~0~^9..0^, _G_~0~^9..0^, _B_~0~^9..0^, _R_~1~^4..0^,
         _G_~3~^4^, _G_~2~^3..0^, _G_~1~^4..0^, _B_~3~^0^, _G_~3~^3..0^, _B_~1~^4..0^, _B_~3~^1^, _B_~2~^3..0^,
         _R_~2~^4..0^, _B_~3~^2^, _R_~3~^4..0^, _B_~3~^3^, PB^4..0^
^.^|  1     ^.^| M^1..0^, _G_~2~^5^, _G_~3~^4^, _G_~3~^5^, _R_~0~^6..0^, _B_~3~^0^, _B_~3~^1^, _B_~2~^4^,
         _G_~0~^6..0^, _B_~2~^5^, _B_~3~^2^, _G_~2~^4^, _B_~0~^6..0^, _B_~3~^3^, _B_~3~^5^, _B_~3~^4^,
         _R_~1~^5..0^, _G_~2~^3..0^, _G_~1~^5..0^, _G_~3~^3..0^, _B_~1~^5..0^, _B_~2~^3..0^, _R_~2~^5..0^,
         _R_~3~^5..0^, PB^4..0^
^.^|  2     ^.^| M^4..0^, _R_~0~^9..0^, _G_~0~^9..0^, _B_~0~^9..0^, _R_~1~^4..0^, _R_~0~^10^, _G_~2~^3..0^,
         _G_~1~^3..0^, _G_~0~^10^, _B_~3~^0^, _G_~3~^3..0^, _B_~1~^3..0^, _B_~0~^10^, _B_~3~^1^, _B_~2~^3..0^,
         _R_~2~^4..0^, _B_~3~^2^, _R_~3~^4..0^, _B_~3~^3^, PB^4..0^
^.^|  6     ^.^| M^4..0^, _R_~0~^9..0^, _G_~0~^9..0^, _B_~0~^9..0^, _R_~1~^3..0^, _R_~0~^10^, _G_~3~^4^,
         _G_~2~^3..0^, _G_~1~^4..0^, _G_~0~^10^, _G_~3~^3..0^, _B_~1~^3..0^, _B_~0~^10^, _B_~3~^1^,
         _B_~2~^3..0^, _R_~2~^3..0^, _B_~3~^0^, _B_~3~^2^, _R_~3~^3..0^, _G_~2~^4^, _B_~3~^3^, PB^4..0^
^.^| 10     ^.^| M^4..0^, _R_~0~^9..0^, _G_~0~^9..0^, _B_~0~^9..0^, _R_~1~^3..0^, _R_~0~^10^, _B_~2~^4^,
         _G_~2~^3..0^, _G_~1~^3..0^, _G_~0~^10^, _B_~3~^0^, _G_~3~^3..0^, _B_~1~^4..0^, _B_~0~^10^,
         _B_~2~^3..0^, _R_~2~^3..0^, _B_~3~^1^, _B_~3~^2^, _R_~3~^3..0^, _B_~3~^4^, _B_~3~^3^, PB^4..0^
^.^| 14     ^.^| M^4..0^, _R_~0~^8..0^, _B_~2~^4^, _G_~0~^8..0^, _G_~2~^4^, _B_~0~^8..0^, _B_~3~^4^, _R_~1~^4..0^,
         _G_~3~^4^, _G_~2~^3..0^, _G_~1~^4..0^, _B_~3~^0^, _G_~3~^3..0^, _B_~1~^4..0^, _B_~3~^1^, _B_~2~^3..0^,
         _R_~2~^4..0^, _B_~3~^2^, _R_~3~^4..0^, _B_~3~^3^, PB^4..0^
^.^| 18     ^.^| M^4..0^, _R_~0~^7..0^, _G_~3~^4^, _B_~2~^4^, _G_~0~^7..0^, _B_~3~^2^, _G_~2~^4^, _B_~0~^7..0^,
         _B_~3~^3^, _B_~3~^4^, _R_~1~^5..0^, _G_~2~^3..0^, _G_~1~^4..0^, _B_~3~^0^, _G_~3~^3..0^, _B_~1~^4..0^,
         _B_~3~^1^, _B_~2~^3..0^, _R_~2~^5..0^, _R_~3~^5..0^, PB^4..0^
^.^| 22     ^.^| M^4..0^, _R_~0~^7..0^, _B_~3~^0^, _B_~2~^4^, _G_~0~^7..0^, _G_~2~^5^, _G_~2~^4^, _B_~0~^7..0^,
         _G_~3~^5^, _B_~3~^4^, _R_~1~^4..0^, _G_~3~^4^, _G_~2~^3..0^, _G_~1~^5..0^, _G_~3~^3..0^, _B_~1~^4..0^,
         _B_~3~^1^, _B_~2~^3..0^, _R_~2~^4..0^, _B_~3~^2^, _R_~3~^4..0^, _B_~3~^3^, PB^4..0^
^.^| 26     ^.^| M^4..0^, _R_~0~^7..0^, _B_~3~^1^, _B_~2~^4^, _G_~0~^7..0^, _B_~2~^5^, _G_~2~^4^, _B_~0~^7..0^,
         _B_~3~^5^, _B_~3~^4^, _R_~1~^4..0^, _G_~3~^4^, _G_~2~^3..0^, _G_~1~^4..0^, _B_~3~^0^, _G_~3~^3..0^,
         _B_~1~^5..0^, _B_~2~^3..0^, _R_~2~^4..0^, _B_~3~^2^, _R_~3~^4..0^, _B_~3~^3^, PB^4..0^
^.^| 30     ^.^| M^4..0^, _R_~0~^5..0^, _G_~3~^4^, _B_~3~^0^, _B_~3~^1^, _B_~2~^4^, _G_~0~^5..0^, _G_~2~^5^,
         _B_~2~^5^, _B_~3~^2^, _G_~2~^4^, _B_~0~^5..0^, _G_~3~^5^, _B_~3~^3^, _B_~3~^5^, _B_~3~^4^,
         _R_~1~^5..0^, _G_~2~^3..0^, _G_~1~^5..0^, _G_~3~^3..0^, _B_~1~^5..0^, _B_~2~^3..0^, _R_~2~^5..0^,
         _R_~3~^5..0^, PB^4..0^
^.^|  3     ^.^| M^4..0^, _R_~0~^9..0^, _G_~0~^9..0^, _B_~0~^9..0^, _R_~1~^9..0^, _G_~1~^9..0^, _B_~1~^9..0^
^.^|  7     ^.^| M^4..0^, _R_~0~^9..0^, _G_~0~^9..0^, _B_~0~^9..0^, _R_~1~^8..0^, _R_~0~^10^, _G_~1~^8..0^,
         _G_~0~^10^, _B_~1~^8..0^, _B_~0~^10^
^.^| 11     ^.^| M^4..0^, _R_~0~^9..0^, _G_~0~^9..0^, _B_~0~^9..0^, _R_~1~^7..0^, _R_~0~^10..11^, _G_~1~^7..0^,
         _G_~0~^10..11^, _B_~1~^7..0^, _B_~0~^10..11^
^.^| 15     ^.^| M^4..0^, _R_~0~^9..0^, _G_~0~^9..0^, _B_~0~^9..0^, _R_~1~^3..0^, _R_~0~^10..15^, _G_~1~^3..0^,
         _G_~0~^10..15^, _B_~1~^3..0^, _B_~0~^10..15^
'''[1:-1] # strip leading and trailing newlines in heredoc

def parse_mode_fields(s):
    """Given a string s, extracts the name of the first bit field and the associated bit range"""
    while s != '':
        fields = s.split('^', 2)
        if len(fields) != 3:
            raise ValueError('syntax error')
        field_name = fields[0]
        bit_range = fields[1]

        range_fields = bit_range.split('..')
        if len(range_fields) == 1:
            bit_a = int(range_fields[0])
            bit_b = bit_a
        elif len(range_fields) == 2:
            bit_a = int(range_fields[0])
            bit_b = int(range_fields[1])
        else:
            raise ValueError('malformed bit range')

        rest = fields[2]
        if rest.startswith(','):
            rest = rest[1:]
        yield field_name, bit_a, bit_b
        s = rest.strip()

def gen_index_bits():
    """Generates a sequence of index bit fields"""
    x = 0
    y = 0
    bit = 0
    while True:
        yield 'IB~' + str(x) + ',' + str(y) + '~^' + str(bit) + '^'
        bit += 1
        if bit == 4 or (bit == 3 and x == 0 and y == 0):
            bit = 0
            x += 1
            if x == 4:
                x = 0
                y += 1

def print_layout_table_body(modes, bit0, bit1):
    print('|================')
    print('>| ' + str(len(modes)) + '+^| *Mode*')
    print('^| *Bit* | ' + ' | '.join(['*' + str(x) + '*' for x, y in modes]))
    for bit in range(bit0, bit1):
        line = '>| ' + ('*' + str(bit) + '*').rjust(4) + ' &nbsp; | '
        line += ' | '.join([y[bit] for x, y in modes])
        print(line)
    print('|================')

# Split lines and extract which modes we have
modes = []
for line in mode_descs.split('\n'):
    fields = line.split('^.^|')
    if len(fields) == 3 and fields[0] == '':
        modes.append((int(fields[1].strip()), fields[2].strip()))
    elif len(fields) == 1 and len(modes) > 0:
        mode_number, existing_fields = modes[-1]
        modes[-1] = (mode_number, existing_fields + ' ' + fields[0].strip())
    else:
        raise ValueError('don''t understand line syntax')

known_fields = set(['M', 'PB',
    '_R_~0~', '_R_~1~', '_R_~2~', '_R_~3~',
    '_G_~0~', '_G_~1~', '_G_~2~', '_G_~3~',
    '_B_~0~', '_B_~1~', '_B_~2~', '_B_~3~',
    ])
two_subset_modes = set([3, 7, 11, 15])

# Generate list of extra index bits for two-subset modes
extra_index_bits = []
for x in gen_index_bits():
    if len(extra_index_bits) >= 17:
        break
    extra_index_bits.append(x)

# Parse modes and turn into array of what bits go where
mode_layouts = []
for mode, fields in modes:
    bits = []
    for field_name, bit_a, bit_b in parse_mode_fields(fields):
        if field_name not in known_fields:
            raise ValueError('unknown field ' + field_name)
        step = 1 if bit_a >= bit_b else -1
        for bit in range(bit_b, bit_a+step, step):
            bits.append(field_name + '^' + str(bit) + '^')

    # Add mode bit annotations
    num_mode_bits = 2 if mode < 2 else 5
    for i in range(num_mode_bits):
        assert bits[i] == 'M^' + str(i) + '^'
        bits[i] += ': *' + str((mode >> i) & 1) + '*'

    # Check that modes have the expected bit count and add extra index bit fields for 2-subset modes
    if mode in two_subset_modes:
        assert len(bits) == 65
        bits += extra_index_bits

    assert len(bits) == 82
    mode_layouts.append((mode, bits))

# Print the two bit layout tables
print('''[[table-bptcbc6hbits]]
.Interpretation of lower bits for BC6H block modes
[width="85%", cols=">1,14*^1"]''')
print_layout_table_body(mode_layouts, 0, 41)

print('''
[[table-bptcbc6hbits2]]
.Interpretation of upper bits for BC6H block modes
[width="80%", cols=">1,14*^1"]''')
print_layout_table_body(mode_layouts, 41, 82)
