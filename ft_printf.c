#include "ft_printf.h"

static int ft_find_specifier(va_list args, char spec)
{
	int len;

	len = 0;
	if (spec == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (spec == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (spec == 'p')
		len = 
	else if (spec == 'd' || spec == 'i')
		len = 
	else if (spec == 'u')
		len = 
	else if (spec == 'x')
		len = 
	else if (spec == 'X')
		len = 
	else if (spec == '%')
		len = ft_putchar('%');
	return(len);
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
