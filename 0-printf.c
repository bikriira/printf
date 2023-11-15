#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - produces output according to a format
 * @format: string that contains the format to print
 * Return: output to stdout, the standard output stream
*/

int _printf(const char *format, ...)
{
    int i = 0;
    static int counter = 0;
    va_list args;
	
	if (format == NULL)
		return (-1);
    va_start(args, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 's' || format[i] == 'c')
            {
                if (format[i] == 's')
                {
                    char *str = va_arg(args, char *);
                    str_handler(str, &counter);
                }
                else if (format[i] == 'c')
                {
                    _putchar(va_arg(args, int), &counter);
                }
            }
            else if (format[i] == '%')
            {
                _putchar('%', &counter);
            }
			else
			{
				_putchar('%', &counter);
				_putchar(format[i], &counter);
			}
        }
        else
        {
            _putchar(format[i], &counter);
        }
        i++;
    }
    va_end(args);
    return (counter);
}

/**
 * str_handler - trigers the _putchar until the whole passed string is done
 * @str: the pointer to the string to be printed
 * @counter: the address of where the counter is stolen
 * Return: void
*/

void str_handler(char *str, int *counter)
{
	int str_indexer = 0;

	while (str[str_indexer] != '\0')
	{
		_putchar(str[str_indexer], counter);
		str_indexer++;
	}
}
