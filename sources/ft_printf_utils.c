#include "ft_printf.h"

size_t	ft_exp(int power, int base)
{
	size_t	res;

	res = 1;
	while (power)
	{
		res *= base;
		power--;
	}
	return (res);
}

int	ft_put_pointer(size_t pointer)
{
	size_t	res;
	size_t	copy_pointer;
	int		count;
	char	*base;

	base = "0123456789abcdef";
	if (pointer == 0)
		return (write(1, "0", 1));
	copy_pointer = pointer;
	count = 0;
	while (copy_pointer && ++count)
		copy_pointer /= 16;
	res = ft_exp(count - 1, 16);
	while (res)
	{
		write(1, &(base[pointer / res]), 1);
		pointer %= res;
		res /= 16;
	}
	return (count);
}

int	ft_put_decimal(int n)
{
	int		res;
	int		copy_n;
	int		sign;
	int		count;

	if (n == 0)
		return (write(1, "0", 1));
	sign = 1;
	count = 0;
	copy_n = n;
	while (copy_n && ++count)
		copy_n /= 10;
	res = (int)ft_exp(count - 1, 10);
	if (n < 0)
	{
		sign = -1;
		count += write(1, "-", 1);
	}
	while (res)
	{
		ft_putchar_fd('0' + (n / res) * sign, 1);
		n %= res;
		res /= 10;
	}
	return (count);
}

int	ft_put_unsigned(unsigned int n)
{
	unsigned int	res;
	unsigned int	copy_n;
	int				count;

	if (n == 0)
		return (write(1, "0", 1));
	count = 0;
	copy_n = n;
	while (copy_n && ++count)
		copy_n /= 10;
	res = (unsigned int)ft_exp(count - 1, 10);
	while (res)
	{
		ft_putchar_fd('0' + (n / res), 1);
		n %= res;
		res /= 10;
	}
	return (count);
}

int	ft_put_hexadecimal(unsigned int n, char reg)
{
	unsigned int	res;
	unsigned int	copy_n;
	int				count;
	char			*base;

	base = "0123456789abcdef";
	if (reg == 'X')
		base = "0123456789ABCDEF";
	if (n == 0)
		return (write(1, "0", 1));
	copy_n = n;
	count = 0;
	while (copy_n && ++count)
		copy_n /= 16;
	res = (unsigned int)ft_exp(count - 1, 16);
	while (res)
	{
		write(1, &(base[n / res]), 1);
		n %= res;
		res /= 16;
	}
	return (count);
}
