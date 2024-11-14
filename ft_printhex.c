/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:01:42 by mbousset          #+#    #+#             */
/*   Updated: 2024/11/13 12:22:31 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex_digits(char *res, int n, int upper)
{
	char	temp;

	while (n-- > 0)
	{
		temp = res[n] - (32 * upper) * (ft_isalpha(res[n]));
		write(1, &temp, 1);
	}
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

int	print_hex(unsigned long n, t_format flags)
{
	char	res[17];
	int		i;
	int		width;
	int		f;

	f = (n == 0);
	zero_cases_hex(n, flags, flags.precision == -1);
	i = fill_arr(res, n);
	width = flags.width - i - (2 * (flags.hashtag) * !f) - (flags.precision > i)
		* (flags.precision - i);
	if (!flags.minus && !f)
		print_pad(width, flags.zero_padding);
	if (flags.hashtag && !flags.zero_padding && !f)
	{
		if (flags.hex_char == 'p')
			flags.hex_char = 'x';
		write(1, "0", 1);
		write(1, &flags.hex_char, 1);
	}
	if (!f)
		print_pad(flags.precision - i, 1);
	print_hex_digits(res, i, (flags.hex_char == 'X'));
	if (flags.minus && !f)
		print_pad(width, flags.zero_padding);
	return (calc_res(flags, i));
}
