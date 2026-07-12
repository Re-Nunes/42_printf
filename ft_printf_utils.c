//FT-putnbr
//FT-putstr
//FT-puthex
//FT-strlen
//FT-POINTER PUTCHAT
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		count += ft_putchar(s[i++]);
	return(count)
}