#include "main.h"

/**
 *_printf- produces output accorting to a format
 *@format: character string
 *Return: the number of characters printed
 *excluding the null byte used to end output to strings
 */

int _printf(const char *format, ...)
{
__attribute__((unused)) int i, x, len = 0;
__attribute__((unused)) char *words, chr, empty[] = "(null)";
if (format != NULL)
{
va_list str;
va_start(str, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
if (format[i + 1] == 'c')
{
chr = va_arg(str, int);
_putchar(chr), len++, i++; }
else if (format[i + 1] == 's')
{
words = va_arg(str, char *);
if (words == NULL)
{
for (x = 0; empty[x] != '\0'; x++)
{
_putchar(empty[x]), len++; } }
else
{
for (x = 0; words[x] != '\0'; x++)
{
_putchar(words[x]), len++; } }
i++; }
else if (format[i + 1] == '%')
{
_putchar(format[i]), i++, len++; }
else
{
_putchar(format[i]), len++; } }
else
{
_putchar(format[i]), len++; } } }
else
len++;
return (len); }
