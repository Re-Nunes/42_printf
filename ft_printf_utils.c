#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		count += ft_putchar(s[i++]);
	return(count);
}

int	ft_putptr(void *ptr)
{
	int	p;

	if (!ptr)
		return (ft_putstr("(nil)"));
	p = ft_putstr("0x") + ft_puthex((unsigned long)ptr, 0);
	return (p);
}

int	ft_putnbr(long long n)
{
	unsigned long long	i;
	int					count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		i = (unsigned long long)(-1 * n);
	}
	else
		i = (unsigned long long)n;
	if (i >= 10)
		count += ft_putnbr(i / 10);
	count += ft_putchar((i % 10) + '0');
	return (count);
}

int	ft_puthex(unsigned long n, char upper)
{
	int	res;
	int	digit;

	res = 0;
	if (n > 15)
		res += ft_puthex(n / 16, upper);
	digit = n % 16;
	if (digit <= 9)
		res += ft_putchar(digit + '0');
	else
	{
		if (upper)
			res += ft_putchar(digit - 10 + 'A');
		else
			res += ft_putchar(digit - 10 + 'a');
	}
	return (res);
}
