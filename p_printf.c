#include <ft_printf.h>

char			*make_precision(char *str, t_printf *p, int len, bool should_free)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	if (p->converter == 's')
	{
		if (p->precision >= len)
			return (str);
		tmp = ft_strsub(str, 0, p->precision);
		if (should_free == true)
			ft_strdel(&str);
		str = tmp;
		return (str);
	}
	else
	{
		if (p->precision <= len)
			return (str);
		tmp2 = ft_strnew(p->precision);
		tmp = tmp2;
		while (i < p->precision - len)
		{
			*tmp = '0';
			tmp++;
			i++;
		}
		tmp = ft_strcpy(tmp, str);
		if (should_free == true)
			ft_strdel(&str);
		str = tmp2;
		return (str);
	}
}

void			flush(char *str, t_printf *p, bool should_free)
{
	int		len;
	char	*tmp;
	char	*tmp2;
	int		i;
	char	c;

	i = 0;
	c = ' ';
	len = ft_strlen(str);
	if (isConverter(p->converter))
	{
		if (p->flags.zero == true && p->precision == -1 && p->flags.moins == false)
			c = '0';
		if (p->flags.space == true && p->converter != 'c' && p->converter != '%' && str[0] != '-')
		{
			p->ret++;
			ft_putchar(' ');
			p->width--;
		}
		if (p->precision != -1 && p->converter != '%')
			str = make_precision(str, p, len, should_free);
		len = ft_strlen(str);
		if (p->width > len)
		{
			if (p->flags.moins == false)
			{
				tmp2 = ft_strnew(p->width);
				tmp = tmp2;
				while (i < p->width - len)
				{
					*tmp = c;
					tmp++;
					i++;
				}
				tmp = ft_strcpy(tmp, str);
				ft_putstr(tmp2);
				ft_strdel(&tmp2);
				p->ret += p->width;
			}
			else
			{
				i = len;
				ft_putstr(str);
				while (i < p->width)
				{
					ft_putchar(' ');
					i++;
				}
				p->ret += p->width;
			}
		}
		else if (p->converter == 'c')
		{
			ft_putchar(str[0]);
			p->ret = p->ret + 1;
		}
		else
		{
			ft_putstr(str);
			p->ret += len;
		}
	}
	else if (p->converter == 'c')
	{
		ft_putchar(str[0]);
		p->ret = p->ret + 1;
	}
	else
	{
		ft_putstr(str);
		p->ret += len;
	}
	if (should_free == true)
		ft_strdel(&str);
	init_struct(p);
}

void			init_struct(t_printf *p)
{
	p->converter = '?';
	p->width = 0;
	p->precision = -1;
	p->mods.h = false;
	p->mods.hh = false;
	p->mods.l = false;
	p->mods.ll = false;
	p->mods.j = false;
	p->mods.z = false;
	p->flags.diese = false;
	p->flags.zero = false;
	p->flags.moins = false;
	p->flags.plus = false;
	p->flags.space = false;
}

int			ft_printf(char *str, ...)
{
	t_printf	p;
	int			i;

	init_struct(&p);
	va_start(p.ap, str);
	i = 0;
	p.ret = 0;
	while (*str != '\0')
	{
		while (str[i] && str[i] != '%')
			i++;
		flush(ft_strsub(str, 0, i), &p, true);
		str += i;
		i = 0;
		if (*str)
		{
			str = process(++str, &p);
			//ft_putchar(*str);
		}
	}
	va_end(p.ap);
	return (p.ret);
}
