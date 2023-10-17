/* _printf.c */
#include "main.h"

/* Function prototype for print_str */
int print_str(char *s);

/**
* _printf - custom printf function
* @format: string with format specifiers
* Return: number of characters printed
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
if (format[i] == '%' && (format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == '%'))
{
switch (format[i + 1])
{
case 'c':
count += _putchar(va_arg(args, int));
i++;
break;
case 's':
count += print_str(va_arg(args, char *));
i++;
break;
case '%':
count += _putchar('%');
i++;
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
* print_str - prints a string
* @s: string to print
* Return: number of characters printed
*/
int print_str(char *s)
{
int i;

if (!s)
return (0);

for (i = 0; s[i]; i++)
_putchar(s[i]);

return (i);
}

