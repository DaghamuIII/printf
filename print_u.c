#include "main.h"
/**
* _print_u - print an unsigned integer (helper function)
* @n: the integer to print
* @count: a pointer to a counter for the number of bytes printed
*/
void _print_u(unsigned int n, int *count)
{
	int lastRetVal;

	if (n > 9)
		_print_u(n / 10, count);
	if (*count < 0)
		return;
	lastRetVal = _putchar('0' + n % 10);
	if (lastRetVal < 0)
		*count = (-1);
	else
		*count += lastRetVal;
}
/**
* print_u - print an unsigned integer
* @args: the va_list with the integer to print as it's next element
*
* Return: the number of bytes printed
*/
int print_u(va_list args)
{
	int count = 0;

	_print_u(va_arg(args, int), &count);
	return (count);
}
