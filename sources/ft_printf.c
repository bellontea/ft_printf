#include "ft_printf.h"

int	ft_define_format(char **format, va_list args)
{
	char	ch;

	(*format)++;
	if (**format == 'c')
	{
		ch = va_arg(args, int);
		return (write(1, &ch, 1));
	}
	else if (**format == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (**format == 'p')
		return (ft_putstr_fd("0x", 1) + ft_put_pointer(va_arg(args, size_t)));
	else if (**format == 'd' || **format == 'i')
		return (ft_put_decimal(va_arg(args, int)));
	else if (**format == 'u')
		return (ft_put_unsigned(va_arg(args, unsigned int)));
	else if (**format == 'x' || **format == 'X')
		return (ft_put_hexadecimal(va_arg(args, unsigned int), **format));
	else if (**format == '%')
		return (write(1, *format, 1));
	return (0);
}

int	ft_printf(const char *output, ...)
{
	va_list	args;
	char	*format;
	int		count;
	int		len;

	count = 0;
	va_start(args, output);
	while (output && *output)
	{
		format = ft_strchr(output, '%');
		if (format)
		{
			write(1, output, format - output);
			count += format - output;
			count += ft_define_format(&format, args);
			output = format + 1;
			continue ;
		}
		len = ft_strlen(output);
		write(1, output, len);
		count += len;
		break ;
	}
	va_end(args);
	return (count);
}
