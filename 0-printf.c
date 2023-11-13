#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: string that contains the format to print
 * Return: output to stdout, the standard output stream
*/

int _printf(const char *format, ...)
{
	int i;
	va_list args;

	i = 0;
	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			int i_specifier;
	
			i++;
			i_specifier = format[i];

			if (i_specifier != '%')
			{
				if (i_specifier == 's')
				{
					while (va_arg(args, int) != '\0')
						_putchar(va_arg(args, int));
				}
				else if (i_specifier == 'c')
				{
					_putchar(va_arg(args, int));
				}
			}
			else if (i_specifier == '%')
			{
				_putchar('%');
			}
		}
		else
		{
			_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (0);
}
