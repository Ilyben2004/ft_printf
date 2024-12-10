#include "ft_printf.h"

int	ft_putnbr_fd(long nb, int fd)
{
    int count;
	
    count = 0;
	if (nb < 0)
	{
		nb = -nb;
		count += ft_putchar_fd('-', fd);
	}
	if (nb > 9)  
        count+= ft_putnbr_fd(nb / 10, fd);
	count += ft_putchar_fd(nb % 10 + 48, fd);
    return (count);
}
