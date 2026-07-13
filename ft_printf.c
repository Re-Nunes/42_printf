#include "ft_printf.h"

static int ft_find_specifier(va_list args, char spec)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (spec == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (spec == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (spec == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (spec == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (spec == 'X')
		 return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (spec == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	int len;

	i = 0;
	len = 0;
	if (!format)
		return(-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += ft_find_specifier(args, format[i]);
		}
		else
		{
			ft_putchar(format[i]);
			len ++;
		}
		i++;
	}
	va_end(args);
	return(len);
}
