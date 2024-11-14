/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:04:44 by mbousset          #+#    #+#             */
/*   Updated: 2024/11/14 17:20:41 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pad(int n, int zeropad)
{
	char	*pad;

	pad = " ";
	if (zeropad)
		pad = "0";
	while (n-- > 0)
	{
		write(1, pad, 1);
	}
	return ;
}

void	zero_cases_hex(unsigned long n, t_format flags, int f)
{
	int	width;

	width = 0;
	if (flags.hashtag && flags.zero_padding && n != 0)
	{
		write(1, "0", 1);
		write(1, &flags.hex_char, 1);
	}
	if (n == 0)
	{
		if (!flags.minus)
		{
			width = flags.width - flags.precision * !f - 1 * f;
			print_pad(width, flags.zero_padding);
		}
		print_pad(flags.precision, 1);
		if (f)
			write(1, "0", 1);
		if (flags.minus)
		{
			width = flags.width - flags.precision * !f - 1 * f;
			print_pad(width, flags.zero_padding);
		}
	}
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
