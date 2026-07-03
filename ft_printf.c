static int ft_findspecifier(va_list args, char *c)
{

}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	int len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_findspecifier(args, format[i])
		}
		else
		{
			ft_putchar_fd(format[i], 1)
			len ++;
		}
	}
	va_end(args);
	return(len);
}
