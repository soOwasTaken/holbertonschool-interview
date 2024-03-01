#!/usr/bin/python3

""" determine the fewest number of coins needed to meet a given amount total"""

def makeChange(coins, total):
    if total <= 0:
        return 0

    # Initialize an array to store the minimum number of coins needed for each total
    min_coins = [float('inf')] * (total + 1)
    min_coins[0] = 0

    # Calculate the minimum number of coins needed for each total from 1 to 'total'
    for i in range(1, total + 1):
        for coin in coins:
            if coin <= i:
                min_coins[i] = min(min_coins[i], min_coins[i - coin] + 1)

    # If min_coins[total] is still float('inf'), it means the total cannot be met by any combination of coins
    if min_coins[total] == float('inf'):
        return -1
    else:
        return min_coins[total]


# Test cases
print(makeChange([1, 2, 25], 37))   # Output: 7
print(makeChange([1256, 54, 48, 16, 102], 1453))   # Output: -1
