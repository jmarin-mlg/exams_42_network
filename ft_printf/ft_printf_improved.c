#include <unistd.h>
#include <stdarg.h>

#ifndef LINUX
# define LINUX 0
#endif

static int	ft_strlen(char *str)
{
	int	len = 0;

	while (*str++)
		++len;

	return (len);
}

static int	numlen(long long int num, int base)
{
	int len = (num < 0) ? 1 : 0;

	if (num < 0)
		num *= -1;

	while (num != 0)
	{
		++len;
		num /= base;
	}

	return (len);
}

static void	put_string(char *string, int *length)
{
	if (!string)
		string = (LINUX == 1) ? "(nil)" : "(null)";

	*length += write(1, string, ft_strlen(string));

	return ;
}

static void	put_digits(long long int number, int base, int *length)
{
	if (number == 0)
	{
		*length += write(1, "0", 1);
		return ;
	}

	char	*hexadecimal = "0123456789abcdef";
	char	buffer[100];
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
	write(1, buffer, len_number);
	*length += len_number;

	return ;
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
				put_string(va_arg(args, char *), &length);
			else if (*format == 'd')
				put_digits((long long int)va_arg(args, int), 10, &length);
			else if (*format == 'x')
				put_digits((long long int)va_arg(args, unsigned int), 16, &length);
		}
		else
			length += write(1, format, 1);

		++format;
	}

	return (va_end(args), length);
}
