#include "ft_printf.h"


int ft_putadresse(unsigned long number)
{
    int count;
    char str[hexsize(number) + 1];
    char *base;
    int i;

    if (!number)
        return(write(1,"(nil)",5));
    i = 0;
    count = 0;
    base = "0123456789abcdef";
    count += write(1,"0x",2);
    while(number > 0)
    {
        str[i++]= base[number % 16];
        number /= 16;
    }
    str[i] = 0;
    return (count + ft_putrevstr(str));
}