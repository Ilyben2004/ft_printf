#include "ft_printf.h"

int	printer(va_list ptr, char c)
{
	unsigned long	a;

	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd((int)va_arg(ptr, int), 1));
	else if (c == 'u')
		return (ft_putnbr_fd((unsigned int)va_arg(ptr, unsigned int), 1));
	else if (c == 'c')
		return (ft_putchar_fd((int)va_arg(ptr, int), 1));
	else if (c == 's')
		return (ft_putstr_fd((char *)va_arg(ptr, char *), 1));
	else if (c == 'x' || c == 'X')
		return (ft_puthex((unsigned int)va_arg(ptr, unsigned int), c));
	else if (c == 'p')
	{
		a = (unsigned long)va_arg(ptr, void *);
		return (ft_putadresse(a));
	}
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	else
		return (ft_putchar_fd('%', 1) + ft_putchar_fd(c, 1));
}

int	ft_printf(const char *format, ...)

{
	int count;
	va_list ptr;
	int size;
	int i;
	int percentage_found;

	if (!format)
		return (-1);
	size = ft_strlen(format);
	va_start(ptr, format);
	count = 0;
	i = 0;
	while (i < size)
	{
		if (format[i] != '%')
			count = count + ft_putchar_fd(format[i], 1);
		else if (format[i] == '%')
		{
			if (!(format[i + 1]) && !percentage_found)
				return (-1);
			if (format[i + 1] != '%')
				percentage_found = 1;
			count += printer(ptr, format[i + 1]);
			i++;
		}
		i++;
	}
	return (count);
}
