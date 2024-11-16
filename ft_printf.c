/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:24:14 by mbousset          #+#    #+#             */
/*   Updated: 2024/11/16 12:20:09 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_flags(const char *s, int *i, t_format *settings)
{
	while (s[*i] == '#' || s[*i] == ' ' || s[*i] == '0' || s[*i] == '-'
		|| s[*i] == '+')
	{
		if (s[*i] == '#')
			settings->hashtag = 1;
		else if (s[*i] == '-')
		{
			settings->minus = 1;
			settings->zero_padding = 0;
		}
		else if (s[*i] == '0' && !settings->minus)
			settings->zero_padding = 1;
		else if (s[*i] == '+')
			settings->plus = 1;
		else if (s[*i] == ' ')
			settings->space = 1;
		(*i)++;
	}
}

void	handle_width_precision(const char *s, int *i, t_format *settings)
{
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		settings->width = settings->width * 10 + (s[*i] - '0');
		(*i)++;
	}
	if (s[*i] == '.')
	{
		settings->precision = 0;
		(*i)++;
		settings->zero_padding = 0;
		while (s[*i] >= '0' && s[*i] <= '9')
		{
			settings->precision = settings->precision * 10 + (s[*i] - '0');
			(*i)++;
		}
	}
}

int	handel_all(const char *s, int *i, t_format *settings, va_list args)
{
	int	temp;

	(*i)++;
	handle_flags(s, i, settings);
	handle_width_precision(s, i, settings);
	if (ft_strchr("cspdiuxX%", s[*i]) != NULL)
	{
		temp = ft_chosefunc(s[*i], args, *settings);
		if (temp == -1)
			return (-1);
		settings->total_len += temp;
	}
	else
	{
		ft_putchar(s[*i]);
		(*settings).total_len++;
	}
	return (0);
}

int	process_string(const char *s, t_format *settings, va_list args)
{
	int	i;

	i = 0;
	while (s[i])
	{
		reset_settings(settings);
		if (s[i] == '%')
		{
			if (handel_all(s, &i, settings, args) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(s[i]) == -1)
				return (-1);
			settings->total_len++;
		}
		if (s[i])
			i++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	t_format	settings;
	va_list		args;

	if (!s || (s[0] == '%' && !s[1]))
		return (-1);
	settings.total_len = 0;
	va_start(args, s);
	if (process_string(s, &settings, args) == -1)
		return (-1);
	va_end(args);
	return (settings.total_len);
}

// int	ft_printf(const char *s, ...)
// {
// 	t_format	settings;
// 	va_list		args;
// 	int			i;

// 	settings.total_len = 0;
// 	va_start(args, s);
// 	i = 0;
// 	if (s == NULL || (s[0] == '%' && s[1] == '\0'))
// 		return (-1);
// 	while (s[i])
// 	{
// 		reset_settings(&settings);
// 		if (s[i] == '%')
// 		{
// 			if (handel_all(s, &i, &settings, args) == -1)
// 				return (-1);
// 		}
// 		else
// 		{
// 			if (ft_putchar(s[i]) == -1)
// 				return (-1);
// 			settings.total_len++;
// 		}
// 		if (s[i] != '\0')
// 			i++;
// 	}
// 	va_end(args);
// 	return (settings.total_len);
// }
