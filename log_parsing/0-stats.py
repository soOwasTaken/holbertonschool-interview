#!/usr/bin/python3
import sys
from collections import defaultdict


def compute_metrics():
    """
    Reads stdin line by line and computes metrics.
    """
    total_size = 0
    status_counts = defaultdict(int)
    line_count = 0

    try:
        for line in sys.stdin:
            parts = line.split()

            if len(parts) >= 7:
                ip_address = parts[0]
                status_code = parts[-2]
                file_size_str = parts[-1]

                if status_code.isdigit():
                    status_code = int(status_code)
                    file_size = int(file_size_str)

                    total_size += file_size
                    status_counts[status_code] += 1
                    line_count += 1

                    if line_count % 10 == 0:
                        print_metrics(total_size, status_counts)

    except KeyboardInterrupt:
        print_metrics(total_size, status_counts)


def print_metrics(total_size, status_counts):
    """
    Prints the current metrics to stdout.
    """
    print("Total file size:", total_size)
    for code in sorted(status_counts.keys()):
        print(f"{code}: {status_counts[code]}")
    print()


if __name__ == "__main__":
    compute_metrics()
