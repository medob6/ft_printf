/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbousset <mbousset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:18:19 by mbousset          #+#    #+#             */
/*   Updated: 2024/11/14 18:40:37 by mbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_format
{
	int	width;
	int	precision;
	int	zero_padding;
	int	hashtag;
	int	hex_char;
	int	minus;
	int	plus;
	int	total_len;
	int	space;
}		t_format;
int		ft_printf(const char *s, ...);
int		print_hex(unsigned long n, t_format settings);
int		ft_chosefunc(char sep, va_list args, t_format flags);
int		ft_print_address(unsigned long n, t_format flags);
void	print_pad(int n, int zeropad);
int		calc_res(t_format flags, int hex_len);
void	zero_cases_hex(unsigned long n, t_format flags, int f);
void	reset_settings(t_format *settings);
int		ft_print_diu(long n, t_format flags);
int		handle_hex(char sep, va_list args, t_format flags);
int		handle_pointer(va_list args, t_format flags);
void	reset_settings(t_format *settings);
int		fill_arr(char *res, unsigned long n);
void	print_hex_digits(char *res, int n, int upper);
int		print_s_c(char p, va_list args, t_format flags);
int		print_c(char c, t_format flags);
int		print_s(char *s, t_format flags, int c_null);

// helpers from libft
char	*ft_itoa(long n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_isalpha(int c);

#endif
