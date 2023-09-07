#!/usr/bin/python3
"""
min_operation.py
"""

def minOperations(n):
	a = 1
	b = 0
	while a < n:
		if n % a == 0:
			b += a
			a += a
		else:
			a += 1
	return b
