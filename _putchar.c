/* _putchar.c */
#include <unistd.h>

/**
* _putchar - writes the character c to stdout
* @c: character to write
* Return: On success 1, or -1 on error and errno is set appropriately.
*/
int _putchar(char c)
{
return write(1, &c, 1);
}

