#include <ft_printf.h>

void			flush(char *str, t_printf *p, bool should_free)
{
	ft_putstr(str);
	p->ret += ft_strlen(str);
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
			str = process(++str, &p);
	}
	va_end(p.ap);
	return (p.ret);
}
