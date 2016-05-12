#include "ft_printf.h"
#include <stdio.h>

/*void		my_print(char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	i = ft_printf(str, va_arg(i);
	va_end(ap);
}
*/
int		main(void)
{
	int	i;

	i = ft_printf("|%5.3d|\n", 123);
	printf("%d\n", i);
	i = printf("|%5.3d|\n", 123);
	printf("%d\n", i);
	return (0);
}
