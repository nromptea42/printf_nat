/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:50:43 by nromptea          #+#    #+#             */
/*   Updated: 2016/05/31 16:05:02 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

typedef int			bool;

# define true 1
# define false 0

typedef struct		s_mod
{
	bool			h;
	bool			hh;
	bool			l;
	bool			ll;
	bool			j;
	bool			z;
}					t_mod;

typedef struct		s_flag
{
	bool			diese;
	bool			zero;
	bool			moins;
	bool			plus;
	bool			space;
}					t_flag;

typedef struct		s_printf
{
	int				ret;
	va_list			ap;
	char			converter;
	int				width;
	int				precision;
	t_mod			mods;
	t_flag			flags;
}					t_printf;


/*
**	ft_printf.c
*/

char				*make_precision(char *str, t_printf *p, int len, bool should_free);
void				flush(char *str, t_printf *p, bool should_free);
void				init_struct(t_printf *p);
int					ft_printf(char *str, ...);

/*
**	process.c
*/

char				*process(char *str, t_printf *p);

/*
**	parse.c
*/

bool				isConverter(char c);
int					parse(char *str, t_printf *p);

/*
**	get_things.c
*/

int					get_width(char *str, t_printf *p);
int					get_precision(char *str, t_printf *p);
int					get_modifier(char *str, t_printf *p);
int					get_flags(char *str, t_printf *p);

#endif
