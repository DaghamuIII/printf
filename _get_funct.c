#include "main.h"
/**
* get_funct - find print function relative to matching specifier
* @c: current specifier to compare
*
* Return: Number of characters printed
*/
int (*get_funct(char c))(va_list)
{
	specifier_t specs_arr[] = {
		{'c', print_c},
		{'s', print_s},
		{'%', print_prcnt},
		{'i', print_i},
		{'d', print_i},
		{'b', print_b},
		{'u', print_u},
		{'o', print_o},
		{'x', print_x},
		{'X', print_X},
		{'S', print_S},
		{'p', print_p},
		{'r', print_rev},
		{'R', print_rot13},
		{ 0, NULL}
	};
	unsigned int i = 0;

	while (specs_arr[i].specifier)
	{
		if (specs_arr[i].specifier == c)
			return (specs_arr[i].f);
		i++;
	}
	return (NULL);
}
