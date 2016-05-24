#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int	i;

	i = ft_printf("|%07.2d|\n", 123);
	printf("%d\n", i);
	i = printf("|%07.2d|\n", 123);
	printf("%d\n", i);
	return (0);
}
