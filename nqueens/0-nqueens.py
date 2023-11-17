#!/usr/bin/python3
"""
N Queens Problem
"""
import sys

def print_solutions(solutions):
    """ Prints the solutions in the required format """
    for solution in solutions:
        print(solution)

def is_safe(board, row, col, n):
    """ Check if it's safe to place a queen at board[row][col] """
    for i in range(col):
        if board[row][i] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True

def solve_n_queens(board, col, n, solutions):
    """ Solves the N Queens problem using backtracking """
    if col >= n:
        solutions.append([[i, row.index(1)] for i, row in enumerate(board)])
        return

    for i in range(n):
        if is_safe(board, i, col, n):
            board[i][col] = 1
            solve_n_queens(board, col + 1, n, solutions)

            board[i][col] = 0

def n_queens(n):
    """ Main function to solve N Queens Problem """
    board = [[0] * n for _ in range(n)]
    solutions = []
    solve_n_queens(board, 0, n, solutions)
    return solutions

def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = n_queens(N)
    print_solutions(solutions)

if __name__ == "__main__":
    main()
