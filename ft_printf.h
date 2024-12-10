#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
int	ft_printf(const char *format, ...);
int	printer(va_list ptr, char c);
int	ft_putadresse(unsigned long number);
int	ft_putchar_fd(char c, int fd);
int	ft_puthex(unsigned int number, char c);
int	ft_putnbr_fd(long nb, int fd);
int	ft_putrevstr(char *str);
int	ft_putstr_fd(char *s, int fd);
int	ft_strlen(const char *s);
int	hexsize(unsigned long test);
#endif
