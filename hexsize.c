#include "ft_printf.h"

int	hexsize(unsigned long test)
{
	int count;

	count = 0;
	if (test == 0)
		return (1);
	while (test > 0)
	{
		count++;
		test /= 16;
	}
	return (count);
}