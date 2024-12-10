#include "ft_printf.h"

int	ft_puthex(unsigned int number, char c)
{
	char *base;
	int size;
	char str[hexsize(number) + 1];
	int i;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	size = hexsize(number);
	while (size > i)
	{
		str[i++] = base[number % 16];
		number /= 16;
	}
	str[i] = 0;
	return (ft_putrevstr(str));
}