#!/usr/bin/python3

""" determine the fewest number of coins needed to meet a given amount total"""


def makeChange(coins, total):
    """ determine the fewest number of coins needed to meet a given amount total"""
    if total <= 0:
        return 0

    newVal = total + 1
    store = {0: 0}

    for i in range(1, total + 1):
        store[i] = newVal

        for coin in coins:
            current = i - coin
            if current < 0:
                continue

            store[i] = min(store[current] + 1, store[i])

    if store[total] == total + 1:
        return -1

    return store[total]
