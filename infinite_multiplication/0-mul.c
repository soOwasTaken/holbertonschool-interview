#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * _isnumber - checks if string is number
 * @s: string
 * Return: 1 if number, 0 if not
 */
int _isnumber(char *s)
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (!isdigit(s[i]))
			return 0;
	}
	return 1;
}

/**
 * _callocX - reserves memory initialized to 0
 * @nmemb: # of bytes
 * Return: pointer
 */
char *_callocX(unsigned int nmemb)
{
	char *p = malloc(nmemb + 1);
	if (p == NULL)
		return NULL;

	for (unsigned int i = 0; i < nmemb; i++)
		p[i] = '0';
	p[nmemb] = '\0';
	return p;
}

/**
 * main - multiplies inf numbers
 * @argc: # of cmd line args
 * @argv: cmd line args
 * Return: No return
 */
int main(int argc, char **argv)
{
	if (argc != 3 || !_isnumber(argv[1]) || !_isnumber(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}

	int num1_zero = atoi(argv[1]) == 0;
	int num2_zero = atoi(argv[2]) == 0;
	if (num1_zero || num2_zero)
	{
		printf("0\n");
		exit(0);
	}

	int len1 = strlen(argv[1]);
	int len2 = strlen(argv[2]);
	int full_len = len1 + len2;
	char *result = _callocX(full_len);
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (int i = len2 - 1; i >= 0; i--)
	{
		int carry = 0;
		for (int j = len1 - 1; j >= 0; j--)
		{
			int temp_loc = i + j + 1;
			int product = (argv[1][j] - '0') * (argv[2][i] - '0') + carry;
			carry = product / 10;
			int sum = (result[temp_loc] - '0') + (product % 10);
			result[temp_loc] = (sum % 10) + '0';
			carry += sum / 10;
		}
		result[i] = carry + '0';
	}

	int start = result[0] == '0' ? 1 : 0;
	for (int i = start; i < full_len; i++)
		printf("%c", result[i]);
	printf("\n");

	free(result);
	return 0;
}
