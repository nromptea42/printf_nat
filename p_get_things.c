#include "ft_printf.h"

int	get_width(char *str, t_printf *p)
{
	int	i;
	char	*tmp;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	tmp = ft_strsub(str, 0, i);
	p->width = ft_atoi(tmp);
	ft_strdel(&tmp);
	return (i - 1);
}
