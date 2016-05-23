#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int	i;

	i = ft_printf("|% c|\n", 'T');
	printf("%d\n", i);
	i = printf("|% c|\n", 'T');
	printf("%d\n", i);
	return (0);
}
