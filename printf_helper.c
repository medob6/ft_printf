/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:26:20 by mbousset          #+#    #+#             */
/*   Updated: 2024/11/13 11:42:01 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_settings(t_format *settings)
{
	settings->width = 0;
	settings->precision = -1;
	settings->hashtag = 0;
	settings->zero_padding = 0;
	settings->hex_char = 'x';
	settings->minus = 0;
	settings->plus = 0;
	settings->space = 0;
}
