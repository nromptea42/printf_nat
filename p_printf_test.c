#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int	i;

	i = ft_printf("|%       d|\n", 123);
	printf("%d\n", i);
	i = printf("|%       d|\n", 123);
	printf("%d\n", i);
	return (0);
}
