#ifndef	MAX_BUFFER_SIZE
	#define MAX_BUFFER_SIZE 55
#else
	#if	MAX_BUFFER_SIZE < 1 || MAX_BUFFER_SIZE > 1024
		#error "MAX_BUFFER_SIZE must be between 1 and 1024"
	#endif
#endif

#include <unistd.h> // For write
#include <stdarg.h> // For va_list, va_start, va_arg, va_end

static void	clean_buffer(char *buffer, int *len_buff)
{
	if (*len_buff + 1 > MAX_BUFFER_SIZE)
	{
		write(1, buffer, *len_buff);

		for (int i = 0; i < MAX_BUFFER_SIZE; i++)
			buffer[i] = '\0';

		*len_buff = 0;
	}
}

static int	ft_strlen(const char *str)
{
	const char	*aux = str;
	int			len = 0;

	while (*aux++)
		++len;

	return (len);
}

static void	put_string(const char *string, char *buffer, int *length, int *len_buff)
{
	const char	*aux = (!string) ? "(null)" : string;

	for (int i = 0; i < ft_strlen(aux); ++i)
	{
		clean_buffer(buffer, len_buff);
		buffer[*len_buff] = aux[i];
		(*len_buff)++;
		(*length)++;
	}
}

static void	put_digit(long long int number, int base, char *buffer, int *length, int *len_buff)
{
	char *hexadecimal = "0123456789abcdef";

	if (number < 0) {
		number *= -1;

		clean_buffer(buffer, len_buff);
		buffer[*len_buff] = '-';
		(*len_buff)++;
		(*length)++;
	}

	if (number >= base)
		put_digit((number / base), base, buffer, length, len_buff);

	clean_buffer(buffer, len_buff);
	buffer[*len_buff] = hexadecimal[number % base];
	(*len_buff)++;
	(*length)++;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	buffer[MAX_BUFFER_SIZE];
	int		len_buff = 0;
	int		length = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			++format;

			switch (*format)
			{
				case 's':
					put_string(va_arg(args, const char *), buffer, &length, &len_buff);
					break;
				case 'd':
					put_digit((long long int) va_arg(args, int), 10, buffer, &length, &len_buff);
					break;
				case 'x':
					put_digit((long long int) va_arg(args, unsigned int), 16, buffer, &length, &len_buff);
					break;
				default:
					clean_buffer(buffer, &len_buff);
					buffer[len_buff++] = '%';
					length++;

					clean_buffer(buffer, &len_buff);
					buffer[len_buff++] = *format;
					length++;
					break;
			}
		}
		else
		{
			clean_buffer(buffer, &len_buff);
			buffer[len_buff++] = *format;
			length++;
		}

		++format;
	}

	va_end(args);

	if (len_buff > 0)
		write(1, buffer, len_buff);

	return length;
}
