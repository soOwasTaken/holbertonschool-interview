/* Description: All 3 + X = All 2 */

#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

#ifdef N
#undef N
#endif
#define N 3

static void print_grid_sum(int grid1[N][N], int grid2[N][N])
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid1[i][j]);
		}

		printf(" %c ", (i == 1 ? '+' : ' '));

		for (j = 0; j < N; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid2[i][j]);
		}
		printf("\n");
	}
}

static void print_grid(int grid[N][N])
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	int grid1[N][N] = {
		{3, 3, 3},
		{3, 3, 3},
		{3, 3, 3}
	};
	int grid2[N][N] = {
		{1, 3, 1},
		{3, 3, 3},
		{1, 3, 1}
	};

	print_grid_sum(grid1, grid2);

	sandpiles_sum(grid1, grid2);

	printf("=\n");
	print_grid(grid1);

	return (EXIT_SUCCESS);
}
