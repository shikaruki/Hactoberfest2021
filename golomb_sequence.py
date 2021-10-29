##Problem Statement: Golomb sequence is a non-decreasing integer sequence where n-th term is equal to number of times n appears in the sequence.

import math
import datetime
import collections
import statistics
import itertools
import time
from datetime import datetime


def input_list():
    ll = list(map(int, input().split(" ")))
    return ll


def golamb(num):
    arr = [0] * (num + 1)
    arr[1] = 1
    for r in range(2, num + 1):
        arr[r] = arr[r - arr[arr[r - 1]]] + 1

    return arr[1 : num + 1]


def main():
    num = int(input())
    arr = golamb(num)
    print(arr)
    return
    for i in arr:
        print(i, end=" ")


if __name__ == "__main__":
    main()
