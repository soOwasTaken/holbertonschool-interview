#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * _isNumber - checks if a string is a number
 * @str: string to check
 * Return: 1 if number, 0 otherwise
 */
int _isNumber(char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[]) {
	long num1, num2, result;

	if (argc != 3) {
		printf("Error\n");
		return 98;
	}

	if (!_isNumber(argv[1]) || !_isNumber(argv[2])) {
		printf("Error\n");
		return 98;
	}

	num1 = atol(argv[1]);
	num2 = atol(argv[2]);
	result = num1 * num2;

	printf("%ld\n", result);
	return 0;
}