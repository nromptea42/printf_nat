#include <ft_printf.h>

#include <stdio.h>

void			flush(char *str, t_printf *p, bool should_free)
{
	int	len;
	char	*tmp;
	char	*tmp2;
	int	i;

	i = 0;
	len = ft_strlen(str);
	//ft_putnbr(len);
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
		p->width = 0;
	}		
	else
	{
		ft_putstr(str);
		p->ret += len;
	}
	if (should_free == true)
		ft_strdel(&str);
}

void			init_struct_p(t_printf *p)
{
	p->ret = 0;
	p->converter = '\0';
	p->width = 0;
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
