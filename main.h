#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1

/*
* Struct fmt - Structure holding format specifier and its function.
* @fmt: The format specifier character.
* @fn: The function associated with the format specifier.
*/
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};

typedef struct fmt fmt_t;

int _printf(const char*, ...);
int handle_print(const char*, int*, va_list, char[], int, int, int, int);
int print_char(va_list, char[], int, int, int, int);
int print_string(va_list, char[], int, int, int, int);
int print_percent(va_list, char[], int, int, int, int);
int print_int(va_list, char[], int, int, int, int);
int print_binary(va_list, char[], int, int, int, int);
int print_unsigned(va_list, char[], int, int, int, int);
int print_octal(va_list, char[], int, int, int, int);
int print_hexadecimal(va_list, char[], int, int, int, int);
int print_hexa_upper(va_list, char[], int, int, int, int);
int print_hexa(va_list, char[], char[], int, char, int, int, int);
int print_non_printable(va_list, char[], int, int, int, int);
int print_pointer(va_list, char[], int, int, int, int);
int get_flags(const char*, int*);
int get_width(const char*, int*, va_list);
int get_precision(const char*, int*, va_list);
int get_size(const char*, int*);
int print_reverse(va_list, char[], int, int, int, int);
int print_rot13string(va_list, char[], int, int, int, int);
int handle_write_char(char, char[], int, int, int, int);
int write_number(int, int, char[], int, int, int, int);
int write_num(int, char[], int, int, int, int, char, char);
int write_pointer(char[], int, int, int, int, char, char, int);
int write_unsgnd(int, int, char[], int, int, int, int);
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int, int);
long int convert_size_unsgnd(unsigned long int, int);

#endif /* MAIN_H */

