#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int	i;

	i = ft_printf("|%05d|\n", -42);
	printf("%d\n", i);
	i = printf("|%05d|\n", -42);
	printf("%d\n", i);
	return (0);
}
