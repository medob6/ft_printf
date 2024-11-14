/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chosefunc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:50:29 by mbousset          #+#    #+#             */
/*   Updated: 2024/11/14 17:02:32 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_signed_integer(va_list args, t_format flags)
{
	return (ft_print_diu(va_arg(args, int), flags));
}

int	handle_unsigned_integer(va_list args, t_format flags)
{
	flags.plus = 0;
	flags.space = 0;
	return (ft_print_diu(va_arg(args, unsigned int), flags));
}

int	handle_char_string(char sep, va_list args, t_format flags)
{
	return (print_s_c(sep, args, flags));
}

int	ft_chosefunc(char sep, va_list args, t_format flags)
{
	if (sep == 'x' || sep == 'X')
		return (handle_hex(sep, args, flags));
	else if (sep == 'p')
		return (handle_pointer(args, flags));
	else if (sep == 'd' || sep == 'i')
		return (handle_signed_integer(args, flags));
	else if (sep == 'u')
		return (handle_unsigned_integer(args, flags));
	else if (sep == 's' || sep == 'c')
		return (handle_char_string(sep, args, flags));
	else if (sep == '%')
		return (write(1, "%", 1));
	return (0);
}
