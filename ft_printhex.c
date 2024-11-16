/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:01:42 by mbousset          #+#    #+#             */
/*   Updated: 2024/11/16 12:12:45 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_digits(char *res, int n, int upper)
{
	char	temp;

	while (n-- > 0)
	{
		temp = res[n] - (32 * upper) * (ft_isalpha(res[n]));
		if (write(1, &temp, 1) == -1)
			return (-1);
	}
	return (0);
}

int	fill_arr(char *res, unsigned long n)
{
	int		i;
	char	*charset;

	i = 0;
	charset = "0123456789abcdef";
	while (n > 0)
	{
		res[i++] = charset[n % 16];
		n /= 16;
	}
	res[i] = '\0';
	return (i);
}

int	calc_res(t_format flags, int hex_len)
{
	int	res;

	res = 0;
	if (hex_len == 0 && flags.precision == -1 && flags.width == 0)
		res = 1;
	if (flags.width > flags.precision)
		res += flags.width;
	else
		res += flags.precision + 2 * flags.hashtag * (hex_len != 0);
	if (hex_len > flags.width && hex_len > flags.precision)
		res = hex_len + 2 * flags.hashtag;
	return (res);
}

int	handel_hashtag(t_format flags, int f)
{
	if (flags.hashtag && !flags.zero_padding && !f)
	{
		if (flags.hex_char == 'p')
			flags.hex_char = 'x';
		if (write(1, "0", 1) == -1)
			return (-1);
		if (write(1, &flags.hex_char, 1) == -1)
			return (-1);
	}
	return (0);
}

int	print_hex(unsigned long n, t_format flags)
{
	char	res[17];
	int		i;
	int		width;
	int		f;

	f = (n == 0);
	if (zero_cases_hex(n, flags, flags.precision == -1) == -1)
		return (-1);
	i = fill_arr(res, n);
	width = flags.width - i - (2 * (flags.hashtag) * !f) - (flags.precision > i)
		* (flags.precision - i);
	if (!flags.minus && !f)
		if (print_pad(width, flags.zero_padding) == -1)
			return (-1);
	if (handel_hashtag(flags, f) == -1)
		return (-1);
	if (!f)
		if (print_pad(flags.precision - i, 1) == -1)
			return (-1);
	if (print_hex_digits(res, i, (flags.hex_char == 'X')) == -1)
		return (-1);
	if (flags.minus && !f)
		if (print_pad(width, flags.zero_padding) == -1)
			return (-1);
	return (calc_res(flags, i));
}
