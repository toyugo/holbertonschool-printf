#include "holberton.h"

/**
 * getPrint - finds the function
 * @s: the format string
 * @ap: the parameters
 * Return: the number of bytes printed
 */
int getPrint(const char *s, va_list ap)
{
	int idx = 0;
	specType fDict[] = {
		{"c", printChar},
		{"d", printInt},
		{"i", printInt},
		{"s", printStr},
		{"b", printBinary},
		{"%", printModulo},
		{"u", printUnsigned},
		{NULL, NULL}
	};

	while (*fDict[idx].spec)
	{
		if (*s == fDict[idx].spec[0])
			return (fDict[idx].f(ap));
		idx++;
	}
	return (0);
}
