# reverse_string.py

import sys

def reverse_string(s):
    if not s:
        return;
    reverse_string(s[1:]);
    print (s[0], end='');

s = sys.argv[1];
rs = reverse_string(s);
print();
