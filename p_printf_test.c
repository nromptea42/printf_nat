#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int	i;

	i = ft_printf("%.5c", 0);
	printf("%d\n", i);
	i = printf("%.5c", 0);
	printf("%d\n", i);
	return (0);
}
