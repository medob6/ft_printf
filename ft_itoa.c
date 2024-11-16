/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:56:29 by mbousset          #+#    #+#             */
/*   Updated: 2024/11/15 16:13:28 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*revstr(char *s)
{
	size_t	i;
	size_t	len;
	char	temp;

	len = ft_strlen(s) - 1;
	i = 0;
	while (i < (len / 2 + 1))
	{
		temp = s[i];
		s[i] = s[len - i];
		s[len - i] = temp;
		i++;
	}
	return (s);
}

static int	count_digit(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(long n)
{
	char	*res;
	int		i;
	int		sign;

	sign = (n < 0);
	i = 0;
	res = malloc((count_digit(n) + (n < 0) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (sign)
		n = -n;
	if (n == 0)
		res[i++] = '0';
	while (n > 0)
	{
		res[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		res[i++] = '-';
	res[i] = '\0';
	return (revstr(res));
}
/**
 *
 * itoa updated :
 * removed cus useing long !!
 *
 * 	// if (n == INT_MIN)
 * 	return (ft_strdup("-2147483648"));
 *
 *
 */
