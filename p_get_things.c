#include "ft_printf.h"

int	get_width(char *str, t_printf *p)
{
	int	i;
	char	*tmp;

	p->width = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	tmp = ft_strsub(str, 0, i);
	p->width = ft_atoi(tmp);
	ft_strdel(&tmp);
	return (i - 1);
}

int	get_precision(char *str, t_printf *p)
{
	int	i;
	char	*tmp;

	p->precision = 0;
	i = 1;
	if (str[i] == '-')
	{
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		return (i);
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	tmp = ft_strsub(str, 1, i - 1);
	p->precision = ft_atoi(tmp);
	ft_strdel(&tmp);
	return (i);
}
