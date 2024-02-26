#include <unistd.h> // For write
#include <stdarg.h> // For va_list, va_start, va_arg, va_end

/*
** Exam version, perhaps not the most readable but quick to write.
**
** It does not comply with the Norme, it is not necessary for the exams.
*/

static void	put_string(char *string, int *length)
{
	string = (!string) ? "(null)" : string;

	while (*string++)
		*length += write(1, string - 1, 1);
}

static void	put_digit(long long int number, int base, int *length)
{
	char	*hexadecimal = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}

	if (number >= base)
		put_digit((number / base), base, length);

	*length += write(1, &hexadecimal[number % base], 1);
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
				put_digit((long long int) va_arg(args, int), 10, &length);
			else if (*format == 'x')
				put_digit((long long int) va_arg(args, unsigned int), 16, &length);
		}
		else
			length += write(1, format, 1);

		++format;
	}

	return (va_end(args), length);
}
