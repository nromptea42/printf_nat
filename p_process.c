#include <ft_printf.h>

char			*process(char *str, t_printf *p)
{
	int		block_size;

	block_size = 0;
	block_size = parse(str, p);
	if (p->converter == 's')
	{
		if (p->mods.l == 1)
			flush((char *)va_arg(p->ap, wchar_t *), p, false);
		else
			flush(va_arg(p->ap, char *), p, false);
	}
	else if (p->converter == 'S')
		flush((char *)va_arg(p->ap, wchar_t *), p, false);
	else if (p->converter == 'd' || p->converter == 'i')
	{
		if (p->mods.h == 1)
			flush(ft_long_long_itoa_base((short)va_arg(p->ap, int), 10), p, true);
		else if (p->mods.hh == 1)
			flush(ft_long_long_itoa_base((signed char)va_arg(p->ap, int), 10), p, true);
		else if (p->mods.l == 1)
			flush(ft_long_long_itoa_base(va_arg(p->ap, long int), 10), p, true);
		else if (p->mods.ll == 1)	
			flush(ft_long_long_itoa_base(va_arg(p->ap, long long int), 10), p, true);
		else if (p->mods.z == 1)
			flush(ft_long_long_itoa_base(va_arg(p->ap, size_t), 10), p, true);
		else if (p->mods.j == 1)
			flush(ft_long_long_itoa_base(va_arg(p->ap, intmax_t), 10), p, true);
		else
			flush(ft_long_long_itoa_base(va_arg(p->ap, int), 10), p, true);
	}
	else if (p->converter == 'D')
		flush(ft_long_long_itoa_base(va_arg(p->ap, long int), 10), p, true);
	else if (p->converter == 'u')
	{
		if (p->mods.h == 1)
			flush(ft_long_long_itoa_base((unsigned short)va_arg(p->ap, int), 10), p, true);
		else if (p->mods.hh == 1)
			flush(ft_long_long_itoa_base((unsigned char)va_arg(p->ap, int), 10), p, true);
		else if (p->mods.l == 1)
			flush(ft_long_long_itoa_base(va_arg(p->ap, unsigned long int), 10), p, true);
		else if (p->mods.ll == 1)	
			flush(ft_long_long_itoa_base(va_arg(p->ap, unsigned long long int), 10), p, true);
		else if (p->mods.z == 1)
			flush(ft_long_long_itoa_base(va_arg(p->ap, size_t), 10), p, true);
		else if (p->mods.j == 1)
			flush(ft_long_long_itoa_base(va_arg(p->ap, uintmax_t), 10), p, true);
		else
			flush(ft_long_long_itoa_base(va_arg(p->ap, unsigned int), 10), p, true);
	}
	else if (p->converter == 'U')
		flush(ft_long_long_itoa_base(va_arg(p->ap, unsigned long int), 10), p, true);
	else if (p->converter == 'X')
	{
		if (p->mods.h == 1)
			flush(ft_long_long_itoa_base((unsigned short)va_arg(p->ap, int), 16), p, true);
		else if (p->mods.hh == 1)
			flush(ft_long_long_itoa_base((unsigned char)va_arg(p->ap, int), 16), p, true);
		else if (p->mods.l == 1)
			flush(ft_long_long_itoa_base(va_arg(p->ap, unsigned long int), 16), p, true);
		else if (p->mods.ll == 1)	
			flush(ft_long_long_itoa_base(va_arg(p->ap, unsigned long long int), 16), p, true);
		else if (p->mods.z == 1)
			flush(ft_long_long_itoa_base(va_arg(p->ap, size_t), 16), p, true);
		else if (p->mods.j == 1)
			flush(ft_long_long_itoa_base(va_arg(p->ap, uintmax_t), 16), p, true);
		else
			flush(ft_long_long_itoa_base(va_arg(p->ap, unsigned int), 16), p, true);
	}
	else if (p->converter == 'x')
	{	
		if (p->mods.h == 1)
			flush(ft_lower_str(ft_long_long_itoa_base((unsigned short)va_arg(p->ap, int), 16)), p, true);
		else if (p->mods.hh == 1)
			flush(ft_lower_str(ft_long_long_itoa_base((unsigned char)va_arg(p->ap, int), 16)), p, true);
		else if (p->mods.l == 1)
			flush(ft_lower_str(ft_long_long_itoa_base(va_arg(p->ap, unsigned long int), 16)), p, true);
		else if (p->mods.ll == 1)	
			flush(ft_lower_str(ft_long_long_itoa_base(va_arg(p->ap, unsigned long long int), 16)), p, true);
		else if (p->mods.z == 1)
			flush(ft_lower_str(ft_long_long_itoa_base(va_arg(p->ap, size_t), 16)), p, true);
		else if (p->mods.j == 1)
			flush(ft_lower_str(ft_long_long_itoa_base(va_arg(p->ap, uintmax_t), 16)), p, true);
		else
			flush(ft_lower_str(ft_long_long_itoa_base(va_arg(p->ap, unsigned int), 16)), p, true);
	}
	else if (p->converter == 'O')
		flush(ft_long_long_itoa_base(va_arg(p->ap, unsigned long int), 8), p, true);
	else if (p->converter == 'o')
	{
		if (p->mods.h == 1)
			flush(ft_long_long_itoa_base((unsigned short)va_arg(p->ap, int), 8), p, true);
		else if (p->mods.hh == 1)
			flush(ft_long_long_itoa_base((unsigned char)va_arg(p->ap, int), 8), p, true);
		else if (p->mods.l == 1)
			flush(ft_lower_str(ft_long_long_itoa_base(va_arg(p->ap, unsigned long int), 8)), p, true);
		else if (p->mods.ll == 1)	
			flush(ft_lower_str(ft_long_long_itoa_base(va_arg(p->ap, unsigned long long int), 8)), p, true);
		else if (p->mods.z == 1)
			flush(ft_lower_str(ft_long_long_itoa_base(va_arg(p->ap, size_t), 8)), p, true);
		else if (p->mods.j == 1)
			flush(ft_lower_str(ft_long_long_itoa_base(va_arg(p->ap, uintmax_t), 8)), p, true);
		else
			flush(ft_lower_str(ft_long_long_itoa_base(va_arg(p->ap, unsigned int), 8)), p, true);
	}
	else if (p->converter == '%')
		flush("%", p, false);
	else if (p->converter == 'c' || p->converter == 'C')
			flush(ft_memset(ft_strnew(2), va_arg(p->ap, int), 1), p , true);
	else if (p->converter == 'p')
		flush(ft_lower_str(ft_long_long_itoa_base(va_arg(p->ap, unsigned long long), 16)), p, true);
	else
	{
		block_size = 0;
		flush("%", p, false);
	}
	//ft_putnbr(block_size);
	return (str + block_size);
}
