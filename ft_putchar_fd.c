#include "ft_printf.h"


int	ft_putchar_fd(char c, int fd)
{
	if (c == 0)
		return (0);
	return (write(fd, &c, 1));
}