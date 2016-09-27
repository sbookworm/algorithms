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


def insert(arr, v):
    arr.append(v)
    init_min_stack(arr)


def pop_min(arr):
    min = arr[0]
    last = arr.pop()
    arr[0] = last
    arr = init_min_stack(arr)
    return min


def test_pop_min():
    test_result = 0
    for i in range(50, 500):
        test_arr = []
        for j in range(i):
            test_arr.append(random.randint(0,1000))

        mstack = init_min_stack(test_arr)
        for k in range(5):
            before_len = len(mstack)
            min = pop_min(mstack)
            after_len = len(mstack)
            for i in range(len(test_arr)):
                if mstack[i] < min:
                    test_result = 1
                    print "failed in compare"
                    break
                if before_len != (after_len + 1):
                    test_result = 1
                    print "failed in length"
                    break

                if test_result == 0:
                    test_result = test_min_stack_fine(mstack)
                    if test_result == 1:
                        print "failed in update stack"
                        break

            if test_result == 1:
                break

    if test_result == 1:
        print "failed pop action test!"
    else:
        print "passed pop action test!"


def test_min_stack_fine(arr):
    test_result = 0
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

    return test_result

def test_init_min_stack():
    test_result = 0
    for i in range(50, 500):
        stack_arr = []
        for j in range(i):
            #stack_arr.append(j)
            stack_arr.append(random.randint(0,500))

        arr = init_min_stack(stack_arr)
        #min = arr[0]
        test_result = test_min_stack_fine(arr)
        if test_result == 1:
            break

    if test_result == 1:
        print "failed init min stack test!"
    else:
        print "passed init min stack test!"


def test_insert_minstack():
    test_result = 0
    for i in range(50, 500):
        test_arr = []
        for j in range(i):
            test_arr.append(random.randint(0,1000))

        mstack = init_min_stack(test_arr)
        for k in range(5):
            before_len = len(mstack)
            insert(test_arr, random.randint(0,1000))
            after_len = len(mstack)
            if before_len != (after_len - 1):
                test_result = 1
                print "failed in length"
                break

            if test_result == 0:
                test_result = test_min_stack_fine(mstack)
                if test_result == 1:
                    print "failed in update stack"
                    break

            if test_result == 1:
                break

    if test_result == 1:
        print "failed insert action test!"
    else:
        print "passed insert action test!"


if __name__ == '__main__':
    test_init_min_stack()

    test_pop_min()

    test_init_min_stack()
