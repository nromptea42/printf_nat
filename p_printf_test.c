#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int	i;

	i = ft_printf("|%05.2d|\n", -1);
	printf("%d\n", i);
	i = printf("|%05.2d|\n", -1);
	printf("%d\n", i);
	return (0);
}
