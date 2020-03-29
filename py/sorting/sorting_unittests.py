# sorting_unittests.py

import unittest
from sorting import insertion_sort, \
    partition;

class SortingTests(unittest.TestCase):
    def test_insertion_sort(self):
        a1 = [19,1,4,7,10];
        b1 = a1[:];
        b1.sort();
        insertion_sort(a1);
        self.assertEqual(a1, b1);

    def test_partition(self):
        a1 = [2,10,5];
        a2 = [2,8,7,1,3,5,6,4];
        q = partition(a1, 0, len(a1) - 1);
        self.assertTrue(q == 1);
        self.assertEqual(a1, [2,5,10]);
        q = partition(a2, 0, len(a2) - 1);
        self.assertTrue(q == 3);
        self.assertEqual(a2, [2,1,3,4,7,5,6,8]);

if __name__ == "__main__":
    unittest.main();
