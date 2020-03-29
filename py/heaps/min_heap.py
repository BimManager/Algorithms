# min_heap.py
from max_heap import parent, left, right

def min_heapify(arr, i):
    l = left(i);
    r = right(i);
    smallest = i;
    if l < len(arr) and arr[l] < arr[smallest]:
        smallest = l;
    if r < len(arr) and arr[r] < arr[smallest]:
        smallest = r;
    if smallest != i:
        arr[i], arr[smallest] = arr[smallest], arr[i];
        min_heapify(arr, smallest);

def build_min_heap(arr):
    for i in range(len(arr)/2-1, -1, -1):
        min_heapify(arr, i);

def heap_min(arr):
    return (arr[0]);

def heap_extract_min(arr):
    arr[0], arr[len(arr)-1] = arr[len(arr)-1], arr[0];
    min = arr.pop();
    min_heapify(arr, 0);

def heap_decrease_key(arr, i, key):
    if arr[i] < key:
        return ;
    arr[i] = key;
    p = parent(i);
    while p >= 0 and arr[p] > arr[i]:
        arr[p], arr[i] = arr[i], arr[p];
        i = p;
        p = parent(p);

def min_heap_insert(arr, key):
    arr.append(key);
    heap_decrease_key(arr, len(arr)-1, key);
