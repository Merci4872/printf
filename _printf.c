#include "main.h"

void flushBuffer(char storage[], int *index);

/**
* _printf - Our version of the printf function.
* @format: Format string with specifications.
* Return: Number of characters printed.
*/
int _printf(const char *format, ...)
{
int iter, output, totalChars = 0, bufferIndex = 0;
int flags, width, precision, size;
va_list argsList;
char outputBuffer[BUFF_SIZE];

if (!format)
return (-1);

va_start(argsList, format);

for (iter = 0; format[iter] != '\0'; iter++)
{
if (format[iter] != '%')
{
outputBuffer[bufferIndex++] = format[iter];
if (bufferIndex == BUFF_SIZE)
flushBuffer(outputBuffer, &bufferIndex);
totalChars++;
}
else
{
flushBuffer(outputBuffer, &bufferIndex);
flags = fetchFlags(format, &iter);
width = fetchWidth(format, &iter, argsList);
precision = fetchPrecision(format, &iter, argsList);
size = fetchSize(format, &iter);
iter++;
output = processSpecifiers(format, &iter, argsList,
outputBuffer, flags, width,
precision, size);
if (output == -1)
return (-1);
totalChars += output;
}
}

flushBuffer(outputBuffer, &bufferIndex);
va_end(argsList);
return (totalChars);
}

/**
* flushBuffer - Outputs buffer contents.
* @storage: Char array.
* @index: Pointer to current buffer position.
*/
void flushBuffer(char storage[], int *index)
{
if (*index > 0)
write(1, storage, *index);
*index = 0;
}

/* Add other helper functions here like fetchFlags, fetchWidth, etc. */

