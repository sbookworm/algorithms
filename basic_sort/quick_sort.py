#!/usr/env python

import random


def partition(arr, p, r):
    base = arr[r]
    i = p -1
    for j in range(p,r):
        if test_array[j] < base:
            i += 1
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp

    arr[r] = arr[i+1]
    arr[i+1] = base
    return i+1

def quick_sort(arr, p, r):
    if p >= r:
        return
    mid = partition(arr, p, r)
    quick_sort(arr, p, mid-1)
    quick_sort(arr, mid+1, r)


if __name__ == '__main__':
    for i in range(50, 150):
        test_array = []
        for j in range(i):
            test_array.append(random.randint(0,100))
        quick_sort(test_array, 0, len(test_array)-1)
        for k in range(len(test_array)-1):
            if test_array[k] > test_array[k+1]:
                print 'error'
        print test_array
