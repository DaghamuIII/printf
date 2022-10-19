include "main.h"

/**
* _printf - print formated string to the buffer,
* mimicking  standard printf of C  lib
* @format: A string made of ordinary characters and format specifier
* Return: intiger value corresp to number of characters printed upon succes
* and -1 when error has occured
*/

int _printf(const char *format, ...)
{
	va_list list;
	int (*print_funct)(va_list);
	int char_counter, funct_return_val;

	if (!format)
		return (-1);
	va_start(list, format);
	for (char_counter = 0; *format; ++format)
	{
		if (*format == '%')
		{
			if (!format[1])
				return (-1);
			print_funct = get_funct(format[1]);
			if (print_funct)
			{
				funct_return_val = print_funct(list);
				if (funct_return_val < 0)
					return (-1);
				char_counter += funct_return_val;
				++format;
				continue;
			}
			funct_return_val = _putchar(*format++);
			if (funct_return_val < 0)
				return (-1);
			char_counter += funct_return_val;
		}
		funct_return_val = _putchar(*format);
		if (funct_return_val < 0)
			return (-1);
		char_counter += funct_return_val;
	}
	va_end(list);
	return (char_counter);
}
