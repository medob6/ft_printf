/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:04:44 by mbousset          #+#    #+#             */
/*   Updated: 2024/11/16 11:06:39 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pad(int n, int zeropad)
{
	char	*pad;

	pad = " ";
	if (zeropad)
		pad = "0";
	while (n-- > 0)
	{
		if (write(1, pad, 1) == -1)
			return (-1);
	}
	return (0);
}

int	handle_zero_hex(t_format flags, int f)
{
	int	width;

	width = flags.width - flags.precision * !f - 1 * f;
	if (!flags.minus && print_pad(width, flags.zero_padding) == -1)
		return (-1);
	if (print_pad(flags.precision, 1) == -1)
		return (-1);
	if (f && ft_putchar('0') == -1)
		return (-1);
	if (flags.minus && print_pad(width, flags.zero_padding) == -1)
		return (-1);
	return (0);
}

int	zero_cases_hex(unsigned long n, t_format flags, int f)
{
	int	width;

	width = 0;
	if (flags.hashtag && flags.zero_padding && n != 0)
		if (ft_putchar('0') == -1 || ft_putchar(flags.hex_char) == -1)
			return (-1);
	if (n == 0)
		if (handle_zero_hex(flags, f) == -1)
			return (-1);
	return (0);
}

int	handle_hex(char sep, va_list args, t_format flags)
{
	flags.hex_char = sep;
	return (print_hex(va_arg(args, unsigned int), flags));
}

int	handle_pointer(va_list args, t_format flags)
{
	flags.hashtag = 1;
	return (ft_print_address((unsigned long)va_arg(args, void *), flags));
}
