#include <ft_printf.h>

static bool		isWidth(char c)
{
	// un nombre ne commençant pas par zéro
	if (c > '0' && c <= '9')
		return (true);
	return (false);
}

static bool		isPrecision(char c)
{
	// .xx
	if (c == '.')
		return (true);
	return (false);
}

static bool		isFlag(char c)
{
	// '#' '0' '-' '+' ' '
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (true);
	return (false);
}

static bool		isModifier(char c)
{
	// h ; hh ; l ; ll ; j ; z
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (true);
	return (false);
}

bool		isConverter(char c)
{
	//"sSpdDioOuUxXcC"
	char	converters[] = "sSdDicCxXoOuU%";

	if (ft_strchr(converters, c))
		return (true);
	else
		return (false);
}

#include <stdio.h> //oui

void	debug(t_printf *p)
{
	printf("h = %d\n", p->mods.h);
	printf("hh = %d\n", p->mods.hh);
	printf("l = %d\n", p->mods.l);
	printf("ll = %d\n", p->mods.ll);
	printf("j = %d\n", p->mods.j);
	printf("z = %d\n", p->mods.z);
}

void	debug2(t_printf *p)
{
	printf("diese = %d\n", p->flags.diese);
	printf("zero = %d\n", p->flags.zero);
	printf("moins = %d\n", p->flags.moins);
	printf("plus = %d\n", p->flags.plus);
	printf("space = %d\n", p->flags.space);
}

int				parse(char *str, t_printf *p)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (isConverter(str[i]))
		{
			p->converter = str[i];
			//ft_putchar(p->converter);
			return (i + 1);
		}	
		else if (isFlag(str[i]))
		{
			i = i + get_flags(str + i, p);
			//debug2(p);
		}
		else if (isWidth(str[i]))
		{
			i = i + get_width(str + i, p);
			//ft_putnbr(p->width);
		}
		else if (isPrecision(str[i]))
		{
			i = i + get_precision(str + i, p);
			//ft_putnbr(p->precision);
		}
		else if (isModifier(str[i]))
		{
			i = i + get_modifier(str + i, p);
			//debug(p);
		}
		else
			return (0);
	}
	return (0);
}
