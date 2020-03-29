# decimal_to_radix.py

import unittest

def decimal_to_radix(num, rad, vdmap, stack=[]):
    if num == 0:
        return ;
    decimal_to_radix(int(num / rad), rad, vdmap, stack);
    print(vdmap[int(num % rad)], end="");
    stack.append(vdmap[int(num % rad)]);
        

class DecimalToRadixTest(unittest.TestCase):
    def test_dec_to_hex(self):
        stack=[];
        hex_digits=['0','1','2','3','4','5','6',\
                '7','8','9','A','B','C','D',\
                'E','F'];
        num=42;
        decimal_to_radix(num, len(hex_digits), hex_digits, stack);
        print();
        res="";
        for digit in stack:
            res+=res.join(digit);
        self.assertEqual("2A", res);

    def test_dec_to_bin(self):
        stack=[];
        bin_digits=['0','1'];
        num=42;
        decimal_to_radix(num, len(bin_digits), bin_digits, stack);
        print();
        res="";
        for digit in stack:
            res+=res.join(digit);
        self.assertEqual("101010", res);
        
if __name__ == "__main__":
    unittest.main();
