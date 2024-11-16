/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:03:41 by mbousset          #+#    #+#             */
/*   Updated: 2024/11/16 10:27:29 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	check_write(int return_write)
// {
// 	if (return_write == -1)
// 		return (-1);
// }

int	zero_cases_address(t_format flags, int f)
{
	int	width;

	width = 0;
	if (!flags.minus && !flags.zero_padding)
	{
		width = flags.width - flags.precision * !f - 1 * f - 2;
		if (print_pad(width, flags.zero_padding) == -1)
			return (-1);
	}
	if (ft_putstr("0x") == -1)
		return (-1);
	if (print_pad(flags.precision, 1) == -1)
		return (-1);
	if (f)
	{
		if (ft_putchar('0') == -1)
			return (-1);
	}
	if (flags.minus || flags.zero_padding)
	{
		width = flags.width - flags.precision * !f - 1 * f - 2;
		if (print_pad(width, flags.zero_padding) == -1)
			return (-1);
	}
	return (0);
}

int	ft_print_address(unsigned long n, t_format flags)
{
	int	res;
	int	temp;

	res = 0;
	temp = 0;
	if (flags.width || flags.precision != -1)
		res = (flags.width - (flags.precision == 1));
	if (n != 0)
	{
		temp = print_hex(n, flags);
		if (temp == -1)
			return (-1);
		res += temp;
	}
	else
	{
		if (zero_cases_address(flags, flags.precision == -1) == -1)
			return (-1);
		if (!flags.width && flags.precision == -1)
			res = calc_res(flags, 0) + 2;
		else
			res += calc_res(flags, 0) + 2 * (flags.width <= flags.precision);
	}
	return (res);
}
