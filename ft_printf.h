#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
int		ft_printchar(va_list args);

#endif