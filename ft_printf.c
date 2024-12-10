#include "ft_printf.h"

int printer(va_list ptr ,char c)
{
    unsigned long a;
    if(c == 'd' || c == 'i')
    {
        return (ft_putnbr_fd((int)va_arg(ptr,int),1));
    }
    else if(c == 'u')
        return (ft_putnbr_fd((unsigned int)va_arg(ptr,unsigned int),1));
    else if (c == 'c')
        return (ft_putchar_fd((int)va_arg(ptr,int),1));
    else if (c == 's')
        return(ft_putstr_fd((char *)va_arg(ptr,char *),1));
    else if (c == 'x' || c == 'X')
          return(ft_puthex((unsigned int)va_arg(ptr,unsigned int),c));
    else if (c == 'p')
    {
        a =(unsigned long) va_arg(ptr,void *);
        return(ft_putadresse(a));
    }
    else if (c == '%')
        return(ft_putchar_fd('%',1));
    else
    {
        ft_putchar_fd('%',1);
        ft_putchar_fd(c,1);
        return (2);
    }
}


int ft_printf(const char *format, ...)

{
    int count;
    va_list ptr;
   

    if (!format)
        return (-1);
    va_start(ptr, format);
    count =0;
    while (*format)
    {
        if(*format != '%' )
            count = count + ft_putchar_fd(*format,1);
        else if (*format == '%')
        {  
            count+= printer(ptr , *(format + 1));
            format++;
        }
        format++;
    }
    return count;
}