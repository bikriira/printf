#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


/**
 * _printf - produces output according to a format
 * @format: string that contains the format to print
 * Return: output to stdout, the standard output stream
*/

int _printf(const char *format, ...)
{
	int i = 0, *counter = malloc(sizeof(int)), counter_helper;
	va_list args;

	if (format == NULL || *format == '%' || counter == NULL)
		return (-1);
	*counter = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[++i])
		{
			if (format[i] == 's')
				str_handler(va_arg(args, char *), counter);
			else if (format[i] == 'c')
				_putchar(va_arg(args, int), counter);
			else if (format[i] == 'd')
				print_digit(va_arg(args, int), 10, counter);
			else if (format[i] == '%')
				_putchar(format[i], counter);
			else
				_putchar('%', counter), _putchar(format[i], counter);
		}
		else
		{
			_putchar(format[i], counter);
		}
		i++;
	}

	va_end(args);
	counter_helper = *counter;
	free(counter);
	return (counter_helper);
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

	if (str == NULL)
	{
		write(1, "(null)", 6);
		*counter += 6;
		return;
	}
	while (str[str_indexer] != '\0')
	{
		_putchar(str[str_indexer], counter);
		str_indexer++;
	}
}

/**
 * print_digit - Solve the printing of dec or hex acording to base argument
 * @num: The number to be parsed
 * @base: The base to consider when parsing the num
 * @counter: The pointer to the counter address
 *
 * Return: void
*/

void print_digit(int num, int base, int *counter)
{
	char *symbols = "0123456789abcdef";

	if (num < 0)
	{
		_putchar('-', counter);
		print_digit(-(long)num, base, counter);
	}
	else if (num < base)
	{
		_putchar(symbols[num], counter);
	}
	else if (num > base)
	{
		int helper1 = num / base;
		int helper2 = num % base;

		print_digit(helper1, base, counter);
		print_digit(helper2, base, counter);
	}
}
