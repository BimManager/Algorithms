# max_heap_unittests.py

import random
import unittest
from max_heap import parent, left, right, max_heapify, \
    build_max_heap, heap_sort, heap_maximum, heap_extract_maximum, \
    heap_increase_key, max_heap_insert

class TestHeapMacros(unittest.TestCase):
    def test_parent(self):
        arr = [4,3,1,5,7,12];
        self.assertEqual(4, arr[parent(1)]);
        self.assertEqual(4, arr[parent(2)]);
        self.assertEqual(3, arr[parent(3)]);
        self.assertEqual(3, arr[parent(4)]);

    def test_left(self):
        for i in range(0, 1000):
            self.assertEqual(2 * i + 1, left(i));

    def test_right(self):
        for i in range(0, 1000):
            self.assertEqual(2 * i + 2, right (i));

    def test_max_heapify(self):
        arr = [16,4,10,14,7,9,3,2,8,1];
        max_heapify(arr, len(arr), 1);
        self.assertEqual(arr, [16,14,10,8,7,9,3,2,4,1]);

    def test_build_max_heap(self):
        arr = [4,1,3,2,16,9,10,14,8,7];
        build_max_heap(arr, len(arr));
        self.assertEqual(arr, [16,14,10,8,7,9,3,2,4,1]);

    def test_heap_sort(self):
        arr = [4,1,3,2,16,9,10,14,8,7];
        heap_sort(arr, len(arr));
        self.assertEqual(arr, [1,2,3,4,7,8,9,10,14,16]);

    def test_heap_extract_max(self):
        arr = [4,4,1,5,3];
        build_max_heap(arr, len(arr));
        max1 = heap_maximum(arr);
        max2 = heap_extract_maximum(arr);
        self.assertEqual(max1, max2);
        self.assertEqual(arr, [4,4,1,3]);

    def test_heap_increase(self):
        arr = [1,10,3];
        build_max_heap(arr, len(arr));
        heap_increase_key(arr, 2, 7);
        self.assertEqual(10, heap_maximum(arr));
        self.assertEqual(arr, [10,1,7]);

    def test_max_heap_insert(self):
        arr = [1,10,3];
        build_max_heap(arr, len(arr));
        self.assertEqual(arr, [10,1,3]);
        max_heap_insert(arr,42);
        self.assertEqual(arr, [42,10,3,1]);
        
if __name__ == "__main__":
    unittest.main();
