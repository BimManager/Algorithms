# max_heap.py

def parent(i):
    if i <= 0:
        return (-1);
    elif i % 2 == 0:
        return ((i >> 1) - 1);
    return (i >> 1);

def left(i):
    return (i << 1 | 1);

def right(i):
    return ((i << 1) + 2);

def max_heapify(arr, size, i):
    l = left(i);
    r = right(i);
    largest = i;
    if l < size and arr[l] > arr[i]:
        largest = l;
    if r < size and arr[r] > arr[largest]:
        largest = r;
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i];
        max_heapify(arr, size, largest);

def build_max_heap(arr, size):
    for i in range(size/2 - 1, -1, -1):
        max_heapify(arr, size, i);

def heap_sort(arr, size):
    build_max_heap(arr, size);
    for i in range(size - 1, 0, -1):
        arr[0], arr[i], = arr[i], arr[0];
        size -= 1;
        max_heapify(arr, size, 0);

def heap_maximum(arr):
    return (arr[0]);


def heap_extract_maximum(arr):
    if not len(arr):
        return;
    max = arr[0];
    arr[0] = arr[len(arr) - 1];
    arr.pop();
    max_heapify(arr, len(arr), 0);
    return (max);
    
 
def heap_increase_key(arr, i, key):
    if arr[i] > key:
        return;
    arr[i] = key;
    while i > 0 and arr[parent(i)] < arr[i]:
        arr[parent(i)], arr[i] = arr[i], arr[parent(i)];
        i = parent(i);

def max_heap_insert(arr, key):
    arr.append(key);
    heap_increase_key(arr, len(arr) - 1, key);
