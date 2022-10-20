#include "main.h"
/**
* print_rot13 - print a string encoded in rot13
* @args: the va_list with the string to print as the next element
*
* Return: the number of bytes printed
*/
int print_rot13(va_list args)
{
	int count = 0, i;
	char *s = va_arg(args, char *);

	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			if ((s[i] >= 'n' && s[i] <= 'z') ||
			    (s[i] >= 'N' && s[i] <= 'Z'))
				count += _putchar(s[i] - 13);
			else
				count += _putchar(s[i] + 13);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}
