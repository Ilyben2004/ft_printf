#include "ft_printf.h"

 int	ft_putstr_fd(char *s, int fd)
{
    if (!s)
    {
        return(write(1,"(null)",6));
    }
	return (write(fd, s, ft_strlen(s)));
}