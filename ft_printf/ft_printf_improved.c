#ifndef	MAX_BUFFER_SIZE
	#define MAX_BUFFER_SIZE 100
#endif

#include <unistd.h> // For write
#include <stdarg.h> // For va_list, va_start, va_arg, va_end

static int	ft_strlen(const char *str)
{
	const char	*aux = str;
	int			len = 0;

	while (*aux++)
		++len;

	return (len);
}

static int	numlen(long long int num, int base)
{
	int len = 0;

	if (num < 0)
	{
		len = 1;
		num *= -1;
	}

	while (num != 0)
	{
		++len;
		num /= base;
	}

	return (len);
}

static void	put_string(const char *string, int *length)
{
	const char	*aux = (!string) ? "(null)" : string;

	*length += write(1, aux, ft_strlen(aux));
}

static void	put_digits(long long int number, int base, int *length)
{
	if (number == 0)
	{
		*length += write(1, "0", 1);
		return ;
	}

	char	*hexadecimal = "0123456789abcdef";
	char	buffer[MAX_BUFFER_SIZE];
	int		len_number = numlen(number, base);
	int		buffer_index = len_number;

	if (number < 0) {
		number *= -1;
		buffer[0] = '-';
	}

	buffer[buffer_index--] = '\0';

	while (number >= base) {
		buffer[buffer_index--] = hexadecimal[number % base];
		number /= base;
	}

	buffer[buffer_index--] = hexadecimal[number % base];
	*length += write(1, buffer, len_number);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length = 0;

	va_start(args, format);

	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			++format;
			if (*format == 's')
				put_string(va_arg(args, const char *), &length);
			else if (*format == 'd')
				put_digits((long long int) va_arg(args, int), 10, &length);
			else if (*format == 'x')
				put_digits((long long int) va_arg(args, unsigned int), 16, &length);
		}
		else
			length += write(1, format, 1);

		++format;
	}

	return (va_end(args), length);
}
