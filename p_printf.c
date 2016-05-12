#include <ft_printf.h>

#include <stdio.h>

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

	i = 0;
	len = ft_strlen(str);
	if (isConverter(p->converter))
	{
		ft_putstr("hello");
		str = make_precision(str, p, len, should_free);
		if (p->width > len)
		{
			tmp2 = ft_strnew(p->width);
			tmp = tmp2;
			while (i < p->width - len)
			{
				*tmp = ' ';
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
			ft_putstr(str);
			p->ret += len;
		}
	}
	else
	{
		ft_putstr(str);
		p->ret += len;
	}
	if (should_free == true)
		ft_strdel(&str);
	p->width = 0;
	p->converter = '?';
}

void			init_struct_p(t_printf *p)
{
	p->ret = 0;
	p->converter = '?';
	p->width = 0;
	p->precision = 0;
}

int			ft_printf(char *str, ...)
{
	t_printf	p;
	int			i;

	init_struct_p(&p);
	va_start(p.ap, str);
	i = 0;
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
