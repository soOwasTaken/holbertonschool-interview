#!/usr/bin/python3
"""testing boxes all by one to see if they can be unlocked"""
import sys
from collections import defaultdict

total_size = 0
status_counts = defaultdict(int)
line_count = 0

try:
    for line in sys.stdin:
        parts = line.split()

        if len(parts) >= 7:
            ip_address = parts[0]
            status_code = parts[-2]
            file_size = int(parts[-1])

            if status_code.isdigit():
                status_code = int(status_code)

                total_size += file_size
                status_counts[status_code] += 1
                line_count += 1

                if line_count % 10 == 0:
                    print("Total file size:", total_size)
                    for code in sorted(status_counts.keys()):
                        print(f"{code}: {status_counts[code]}")
                    print()

except KeyboardInterrupt:
    print("Total file size:", total_size)
    for code in sorted(status_counts.keys()):
        print(f"{code}: {status_counts[code]}")