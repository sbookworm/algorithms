#!/usr/env python

import random

def merge_sort(arr):
    arr_len = len(arr)
    if arr_len <= 1:
        return arr
    left_len = arr_len/2
    left = merge_sort(arr[:left_len])
    right = merge_sort(arr[left_len:])

    return merge(left, right)


def merge(left, right):
    i = len(left)
    j = len(right)

    result = []
    a = 0
    b = 0

    while a<i and b<j:
        if left[a] < right[b]:
            result.append(left[a])
            a += 1
        else:
            result.append(right[b])
            b += 1

    if a < i:
        result.extend(left[a:])
    if b < j:
        result.extend(right[b:])
    return result


if __name__ == '__main__':
    for i in range(50, 1500):
        test_array = []
        for j in range(i):
            test_array.append(random.randint(0, 1000))
        sorted_arr = merge_sort(test_array)
        for k in range(len(sorted_arr)-1):
            if sorted_arr[k] > sorted_arr[k+1]:
                print "error"
            else:
                print "="
    print "ok"
