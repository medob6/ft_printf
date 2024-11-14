/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:29:35 by mbousset          #+#    #+#             */
/*   Updated: 2024/11/14 18:43:07 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pad(int len, int zeropad)
{
	char	pad;

	pad = ' ';
	if (zeropad)
		pad = '0';
	while (len--)
		ft_putchar_fd(pad, 1);
	return (len);
}

void	print_str(char *str, int len)
{
	int	j;

	j = 0;
	while (len--)
		write(1, &str[j++], 1);
}

int	print_c(char c, t_format flags)
{
	int		len;
	char	s[2];
	
	s[0] = c;
	if (c != '\0')
		s[1] = '\0';
	len = print_s(s, flags, (c == '\0'));
	return (len);
}

int	print_s(char *s, t_format flags,int c_null)
{
	int	len;
	int	count;

	len = 0;
	if (s == NULL)
		s = "(null)";
	if (s[0] == '\0' && c_null)
		len++;
	len += ft_strlen(s);
	if (ft_strlen(s) > (size_t)flags.precision && flags.precision != -1)
		len = flags.precision;
	count = len;
	if (!flags.minus && flags.width > len)
		count += pad(flags.width - len, flags.zero_padding);
	print_str(s, len);
	if (flags.minus && flags.width > len)
		count += pad(flags.width - len, 0);
	return (count);
}

int	print_s_c(char p, va_list args, t_format flags)
{
	int	sum;

	sum = 0;
	if (p == 'c')
		sum = print_c((char)va_arg(args, int), flags);
	else
		sum = print_s(va_arg(args, char *), flags,0);
	return (sum);
}
