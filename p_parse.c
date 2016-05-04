#include <ft_printf.h>

static bool		isWidth(char c)
{
	// un nombre ne commençant pas par zéro
	(void)c;
	return (false);
}

static bool		isPrecision(char c)
{
	// .xx
	(void)c;
	return (false);
}

static bool		isFlag(char c)
{
	// "#0-+ "
	(void)c;
	return (false);
}

static bool		isModifier(char c)
{
	// h ; hh ; l ; ll ; j ; z
	(void)c;
	return (false);
}

static bool		isConverter(char c)
{
	//"sSpdDioOuUxXcC"
	char	converters[] = "sdicxXoOuU%";

	if (ft_strchr(converters, c))
		return (true);
	else
		return (false);
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
			return (i + 1);
		}	
		else if (isFlag(str[i]))
			(void)str;
		else if (isWidth(str[i]))
			(void)str;
		else if (isPrecision(str[i]))
			(void)str;
		else if (isModifier(str[i]))
			(void)str;
		else
			return (0);
		i++;
	}
	return (0);
}
