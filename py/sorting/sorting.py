# sorting.py

def insertion_sort(arr):
    for i in range(1, len(arr)):
        j = i;
        while j > 0 and arr[j] < arr[j - 1]:
            arr[j], arr[j - 1] = arr[j - 1], arr[j];
            j -= 1;

def partition(arr, p, r):
    x = arr[r];
    i = p - 1;
    for j in range(p, r):
        if arr[j] <= x:
            i += 1;
            arr[i], arr[j] = arr[j], arr[i];
    arr[r], arr[i + 1] = arr[i + 1], arr[r];
    return (i + 1); 


def quicksort(arr, p, r):
    if p < r:
        return ;
    q = partition(arr, p, r);
    quicksort(arr, p, q - 1);
    quicksort(arr, q + 1, r);
    
