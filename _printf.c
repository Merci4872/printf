/* _printf.c */
#include "main.h"
#include <stdarg.h>

/* Forward declaration for string print function */
int print_str(char *s);

/**
* _printf - Our custom printf
* @format: string format
* Return: char count
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
(format[i + 1] == 'c' ||
format[i + 1] == 's' ||
format[i + 1] == '%'))
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
* print_str - Print string
* @s: string
* Return: char count
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

