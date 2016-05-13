/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:33:20 by nromptea          #+#    #+#             */
/*   Updated: 2016/05/13 18:37:35 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_rec(long long n, char *res, int base)
{
	if (n >= base)
		res = itoa_rec(n / base, res, base);
	*res = "0123456789ABCDEF"[n % base];
	*(res + 1) = '\0';
	return (res + 1);
}

char		*ft_long_long_itoa_base(long long int n, int base)
{
	char			*res;
	long long int	nb;
	int				nbch;
	long long		tmp;
	int				i;

	nb = n;
	nbch = 1;
	i = 0;
	tmp = n;
	if (nb < 0)
		nb = -nb;
	while (nb >= base)
	{
		nb = nb / base;
		nbch++;
	}
	if (!(res = (char *)malloc(sizeof(char) * (nbch + 1))))
		return (NULL);
	if (tmp < 0)
	{
		res[i] = '-';
		i++;
		tmp = -tmp;
	}
	itoa_rec(tmp, res + i, base);
	return (res);
}
