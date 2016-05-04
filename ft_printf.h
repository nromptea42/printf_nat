#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

typedef int			bool;

# define true 1
# define false 0

typedef struct		s_printf
{
	int				ret;
	va_list			ap;
	char			converter;
	int				width;
}					t_printf;

/*
**	ft_printf.c
*/

void				flush(char *str, t_printf *p, bool should_free);
int					ft_printf(char *str, ...);

/*
**	process.c
*/

char				*process(char *str, t_printf *p);

/*
**	check.c
*/

int					parse(char *str, t_printf *p);


#endif
