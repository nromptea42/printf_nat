/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:50:43 by nromptea          #+#    #+#             */
/*   Updated: 2016/05/11 18:28:51 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int				precision;
}					t_printf;

/*
**	ft_printf.c
*/

void				flush(char *str, t_printf *p, bool should_free);
void				init_p_struct(t_printf *p);
int					ft_printf(char *str, ...);

/*
**	process.c
*/

char				*process(char *str, t_printf *p);

/*
**	parse.c
*/

bool					isConverter(char c);
int					parse(char *str, t_printf *p);

/*
**	get_things.c
*/

int			get_width(char *str, t_printf *p);
int			get_precision(char *str, t_printf *p);

#endif
