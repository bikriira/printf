#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char c, int *counter_addr);
void str_handler(char *str, int *counter);
void print_digit(int num, int base, int *counter);
/*void print_seg(char *format, va_list arg, int *counter);*/

#endif
