#include "ft_printf.h"

int	get_width(char *str)
{
	int	i;
	int	j;
	char	*tmp;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	tmp = ft_strsub(str, 0, i);
	j = ft_atoi(tmp);
	ft_strdel(&tmp);
	ft_putnbr(j);
	ft_putchar('\n');
	return (j);
}
