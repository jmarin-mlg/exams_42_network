#include <unistd.h> // For write
#include <stdarg.h> // For va_list, va_start, va_arg, va_end, va_copy
#include <stdlib.h> // For malloc, free

static int	ft_strlen(const char *str)
{
	const char	*aux;
	int			len;

	if (!str)
		return (0);

	aux = str;
	len = 0;

	while (*aux++)
		++len;

	return (len);
}

static int	numlen(long long int num, int base)
{
	int	len = (num <= 0) ? 1 : 0;

	if (num < 0)
		num *= -1;

	while (num != 0)
	{
		++len;
		num /= base;
	}

	return (len);
}

static int calculate_buffer_size(const char *format, va_list args)
{
	va_list		aux_args;
	const char	*aux_format = format;
	int			size = 0;

	if (!format)
		return (0);

	va_copy(aux_args, args);

	while (*aux_format)
	{
		if (*aux_format == '%')
		{
			++aux_format;

			switch (*aux_format)
			{
			case 's':
				size += ft_strlen(va_arg(aux_args, const char *));
				break;
			case 'd':
				size += numlen(va_arg(aux_args, int), 10);
				break;
			case 'x':
				size += numlen(va_arg(aux_args, unsigned int), 16);
				break;
			default:
				size += 2;
				break;
			}
		}
		else
			++size;

		++aux_format;
	}

	va_end(aux_args);

	return (size);
}

static void	put_string(const char *string, char *buffer, int *length)
{
	const char	*aux = (!string) ? "(null)" : string;

	for (int i = 0; i < ft_strlen(aux); ++i)
		buffer[(*length)++] = aux[i];
}

static void	put_digit(long long int number, int base, char *buffer, int *length)
{
	char *hexadecimal = "0123456789abcdef";

	if (number < 0) {
		number *= -1;
		buffer[(*length)++] = '-';
	}

	if (number >= base)
		put_digit((number / base), base, buffer, length);

	buffer[(*length)++] = hexadecimal[number % base];
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*buffer;
	int		buffer_size;
	int		length = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	buffer_size = calculate_buffer_size(format, args);
	buffer = (char *) malloc(buffer_size + 1);
	if (!buffer) {
        va_end(args);
        return (-1);
    }

	while (*format)
	{
		if (*format == '%')
		{
			++format;

			switch (*format)
			{
				case 's':
					put_string(va_arg(args, const char *), buffer, &length);
					break;
				case 'd':
					put_digit((long long int) va_arg(args, int), 10, buffer, &length);
					break;
				case 'x':
					put_digit((long long int) va_arg(args, unsigned int), 16, buffer, &length);
					break;
				default:
					buffer[length++] = '%';
					buffer[length++] = *format;
					break;
			}
		}
		else
			buffer[length++] = *format;

		++format;
	}

	va_end(args);

	if (length > 0)
		write(1, buffer, length);

	return (free(buffer), length);
}
