#!/usr/bin/python3
"""
stats.py Module

This module provides functionality to compute metrics from web server log entries that are fed from stdin.

Metrics computed:
1. Total file size across all requests.
2. Count of requests for each HTTP status code.

The expected format for each log entry:
IP_ADDRESS - - [TIMESTAMP] "REQUEST" STATUS_CODE FILE_SIZE
e.g., 127.0.0.1 - - [26/Sep/2023:14:55:36 -0700] "GET /index.html HTTP/1.1" 200 2326

After processing every 10 lines, the module prints the metrics to stdout. If interrupted by a keyboard signal (like Ctrl+C),
the current metrics will be printed.

Usage:
Pipe log entries into the script. For example:
$ cat server.log | ./stats.py

Dependencies:
- sys
- collections.defaultdict

"""

import sys
from collections import defaultdict


def compute_metrics():
    """
    Reads stdin line by line and computes metrics for server logs.

    This function processes each line, extracts relevant metrics, and prints results after every 10 lines.
    In the case of a KeyboardInterrupt, the current metrics will also be printed.
    """
    total_size = 0
    status_counts = defaultdict(int)
    line_count = 0

    try:
        for line in sys.stdin:
            parts = line.split()

            if len(parts) >= 7:
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
    Prints the current server log metrics to stdout.

    Args:
    - total_size (int): Total file size accumulated so far.
    - status_counts (dict): Dictionary containing counts of each HTTP status code.
    """
    print("Total file size:", total_size)
    for code in sorted(status_counts.keys()):
        print(f"{code}: {status_counts[code]}")
    print()


if __name__ == "__main__":
    compute_metrics()
