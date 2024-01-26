#include "holberton.h"

/**
 * is_digit - Check if a string contains only digits
 * @str: The string to check
 *
 * Return: 1 if all characters are digits, 0 otherwise
 */
int is_digit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * multiply - Multiply two numbers represented as strings
 * @num1: The first number
 * @num2: The second number
 *
 * Return: A pointer to the result as a string
 */
char *multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j, carry, product;
	int *result;
	char *res_str;

	/* Calculate the lengths of the input numbers */
	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	/* Initialize the result array */
	result = malloc(sizeof(int) * (len1 + len2));
	if (result == NULL)
		print_error_and_exit();

	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	/* Multiply each digit of num1 with each digit of num2 */
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			product = (num1[i] - '0') * (num2[j] - '0') + carry + result[i + j + 1];
			result[i + j + 1] = product % 10;
			carry = product / 10;
		}
		result[i + j + 1] = carry;
	}

	/* Convert the result array to a string */
	res_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (res_str == NULL)
		print_error_and_exit();

	for (i = 0; i < len1 + len2; i++)
		res_str[i] = result[i] + '0';
	res_str[i] = '\0';

	free(result);
	return (res_str);
}

int main(int argc, char *argv[])
{
	char *num1, *num2, *result;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		print_error_and_exit();
	}

	num1 = argv[1];
	num2 = argv[2];
	result = multiply(num1, num2);
	printf("%s\n", result);

	free(result);
	return (0);
}

/**
 * print_error_and_exit - Print "Error" and exit with status 98
 */
void print_error_and_exit(void)
{
	printf("Error\n");
	exit(98);
}
