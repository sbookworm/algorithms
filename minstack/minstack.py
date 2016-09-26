#!/usr/env python

import random

def minstack_once_sort(arr):
    stack_len = len(arr)
    changed = 0
    i = stack_len/2
    while i > 0:
        if 2*(i-1)+1 <= stack_len-1 and arr[i-1] > arr[2*(i-1)+1]:
            temp = arr[2*(i-1)+1]
            arr[2*(i-1)+1] = arr[i-1]
            arr[i-1] = temp
            changed = 1

        if 2*(i-1)+2 <= stack_len-1 and arr[i-1] > arr[2*(i-1)+2]:
            temp = arr[2*(i-1)+2]
            arr[2*(i-1)+2] = arr[i-1]
            arr[i-1] = temp
            changed = 1

        i -= 1

    return changed


def init_min_stack(arr):
    while True:
        changed = minstack_once_sort(arr)
        if changed == 0:
            break

    return arr


def test_init_min_stack():
    test_result = 0
    for i in range(50,100):
        stack_arr = []
        for j in range(3,100):
            #stack_arr.append(j)
            stack_arr.append(random.randint(0,500))

        arr = init_min_stack(stack_arr)
        #min = arr[0]
        arr_len = len(arr)
        for k in range(arr_len/2):
            child_1 = 2*k + 1
            child_2 = 2*k + 2
            if child_1 >= arr_len:
                break
            if arr[child_1] < arr[k]:
                test_result = 1
                break

            if child_2 >= arr_len:
                break

            if arr[child_2] < arr[k]:
                test_result = 1
                break

    if test_result == 1:
        print "failed test!"
    else:
        print "passed test!"    


if __name__ == '__main__':
    test_init_min_stack()

