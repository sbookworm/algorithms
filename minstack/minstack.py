#!/usr/env python


stack_arr = [9,6,4,7,23,8,2,3]


def init_min_stack(arr):

    stack_len = len(arr)
    i = stack_len/2
    while i >= 0:
        if 2*(i-1)+1 <= stack_len-1 and arr[i-1] > arr[2*(i-1)+1]:
            temp = arr[2*(i-1)+1]
            arr[2*(i-1)+1] = arr[i-1]
            arr[i-1] = temp

        if 2*(i-1)+2 <= stack_len-1 and arr[i-1] > arr[2*(i-1)+2]:
            temp = arr[2*(i-1)+2]
            arr[2*(i-1)+2] = arr[i-1]
            arr[i-1] = temp

        i -= 1
    return arr


if __name__ == '__main__':
    print init_min_stack(stack_arr)
