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
	return (i);
}

int	get_precision(char *str, t_printf *p)
{
	int	i;
	char	*tmp;

	p->precision = -1;
	i = 1;
	if (str[i] == '-' || (str[i] < '0' && str[i] > '9'))
	{
		if (str[i] == '-')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		p->precision = 0;
		return (i);
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	tmp = ft_strsub(str, 1, i - 1);
	p->precision = ft_atoi(tmp);
	ft_strdel(&tmp);
	return (i);
}

int	get_modifier(char *str, t_printf *p)
{
	int		i;

	i = 1;
	if (str[0] == 'h')
	{
		if (str[1] != 'h')
			p->mods.h = true;
		else
		{
			p->mods.hh = true;
			i = 2;
		}
	}
	if (str[0] == 'l')
	{
		if (str[1] != 'l')
			p->mods.l = true;
		else
		{
			p->mods.ll = true;
			i = 2;
		}
	}
	if (str[0] == 'j')
		p->mods.j = true;
	if (str[0] == 'z')
		p->mods.z = true;
	return (i);
}
