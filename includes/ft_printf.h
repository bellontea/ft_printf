#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_define_format(char **format, va_list args);
int		ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
size_t	ft_exp(int power, int base);
int		ft_put_pointer(size_t pointer);
int		ft_put_decimal(int n);
int		ft_put_unsigned(unsigned int n);
int		ft_put_hexadecimal(unsigned int n, char reg);

#endif
