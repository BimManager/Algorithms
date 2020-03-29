# min_heap_unittests.py

import unittest
from min_heap import min_heapify, build_min_heap, \
    heap_min, heap_extract_min, heap_decrease_key, \
    min_heap_insert

class MinHeapTestCases(unittest.TestCase):
    def test_min_heapify(self):
        a1 = [5,1,3];
        a2 = [5,2,3,1,7];
        min_heapify(a1, 0);
        min_heapify(a2, 0);
        self.assertEqual(a1, [1,5,3]);
        self.assertEqual(a2, [2,1,3,5,7]);

    def test_build_min_heap(self):
        a1 = [3,2,7,1,9];
        a2 = [4,1,3];
        build_min_heap(a1);
        build_min_heap(a2);
        self.assertEqual(a1, [1,2,7,3,9]);
        self.assertEqual(a2, [1,4,3]);
        
    def test_heap_min(self):
        a1 = [10,14,1];
        build_min_heap(a1);
        self.assertEqual(a1, [1,14,10]);
        self.assertEqual(heap_min(a1), 1);
        
    def test_extract_min(self):
        a1 = [10,14,1];
        build_min_heap(a1);
        heap_extract_min(a1);
        self.assertEqual(a1, [10, 14]);

    def test_heap_descrease_key(self):
        a1 = [10,14,7];
        build_min_heap(a1);
        heap_decrease_key(a1, 2, 3);
        self.assertEqual(a1, [3,14,7]);

    def test_heap_descrease_key(self):
        a1 = [10,14,7];
        build_min_heap(a1);
        min_heap_insert(a1, 3);
        self.assertEqual(a1, [3,7,10,14]);
        
if __name__ == '__main__':
    unittest.main();
    
