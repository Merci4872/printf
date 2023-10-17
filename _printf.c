#include "main.h"
#include <stdarg.h>

int _putchar(char c);
int print_int(int n);
int print_str(char *s);

/**
* _printf - A function that produces output according to a format.
* @format: The format string.
*
* Return: number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list args;
unsigned int i = 0, count = 0;

if (!format)
return (-1);

va_start(args, format);

while (format[i])
{
if (format[i] == '%' &&
(format[i + 1] == 'c' || format[i + 1] == 's' ||
format[i + 1] == '%' || format[i + 1] == 'd' ||
format[i + 1] == 'i'))
{
i++;
switch (format[i])
{
case 'c':
count += _putchar(va_arg(args, int));
break;
case 's':
count += print_str(va_arg(args, char *));
break;
case '%':
count += _putchar('%');
break;
case 'd':
case 'i':
count += print_int(va_arg(args, int));
break;
}
}
else
{
_putchar(format[i]);
count++;
}
i++;
}

va_end(args);
return (count);
}

/**
* print_int - Prints an integer.
* @n: The integer.
*
* Return: number of digits printed.
*/
int print_int(int n)
{
int count = 0;
if (n < 0)
{
_putchar('-');
n = -n;
}
if (n / 10)
count += print_int(n / 10);
_putchar(n % 10 + '0');
return (count + 1);
}

/**
* print_str - Prints a string.
* @s: The string.
*
* Return: number of characters printed.
*/
int print_str(char *s)
{
int i;
if (!s)
s = "(null)";
for (i = 0; s[i]; i++)
_putchar(s[i]);
return (i);
}

