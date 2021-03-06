#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	const char	ch = c;

	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}
