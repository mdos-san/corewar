/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:22:09 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 10:32:35 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>

typedef struct	s_pri
{
	char				*str;
	char				*tmp;
	char				*tmp2;
	char				*tmp3;
	char				*sub;
	char				*stock;
	char				*num;
	char				*res;
	char				char_conv;
	unsigned char		char_uconv;
	wchar_t				*str_unicode;
	wint_t				char_unicode;
	int					ret;
	int					convc;
	int					init;
	int					i;
	int					k;
	unsigned int		uniconv;
	size_t				len;
	size_t				size_conv;
	short				short_conv;
	unsigned short		short_unconv;
	intmax_t			intmax_conv;
	uintmax_t			uintmax_conv;
	long				longint;
	unsigned long		unlong;
	unsigned long long	unlonglong;
	long long			longlong;
	int					convdi;
	void				*voidconv;
}				t_pri;

int				ft_printf(char *format, ...);
int				check1(char *format, int i);
int				check2(char *format, int i);
int				s_conv(char *str, t_pri var, va_list pa);
int				c_conv(char *str, t_pri var, va_list pa);
int				display(char *sub, t_pri var, va_list pa);
char			*min_str(char *sub, char *tmp, t_pri var, int i);
char			*except_pre(char *stock, int len, char *sub);
char			*except_minus(char *res);
int				min_char(char *sub, int convc, t_pri var, int i);
int				min_char0(char *sub, int convc, t_pri var, int i);
int				min_charuni(char *sub, char *convc, t_pri var, int i);
int				di_conv(char *sub, t_pri var, va_list pa);
int				o_conv(char *sub, t_pri var, va_list pa);
int				u_conv(char *sub, t_pri var, va_list pa);
int				x_conv(char *sub, t_pri var, va_list pa);
int				p_conv(char *sub, t_pri var, va_list pa);
int				no_conv(char *sub, t_pri var);
int				xmaj_conv(char *sub, t_pri var, va_list pa);
int				umaj_conv(char *sub, t_pri var, va_list pa);
int				dmaj_conv(char *sub, t_pri var, va_list pa);
int				omaj_conv(char *sub, t_pri var, va_list pa);
int				smaj_conv(char *sub, t_pri var, va_list pa);
int				cmaj_conv(char *sub, t_pri var, va_list pa);
int				percent_conv(char *sub, t_pri var);
char			*min_pre(char *sub, char *stock, t_pri var);
char			*fucking_flag(char *sub, char *res, t_pri var, char *str);
char			*ft_itoa_base(long long int n, unsigned int base);
char			*str_upper(char *str);
char			*ft_itoa_ulong(unsigned long long n, unsigned int base);
void			free_str(char *str, char *str1, char *str2, char *str3);
void			free_str3(char *str, char *str1, char *str2);
char			*unicode_mask(wint_t c_uni);
char			*unicode_masks(wchar_t s_uni);
int				conv_bin(char *tab);
char			*split_tab(char *res);
int				test_len(char *res, char *str);
char			*hashtag_x(char *res, char *str, t_pri var);
char			*hashtag_o(char *res, char *str, t_pri var);
int				except_smaj(wchar_t *str, int len);
long long int	ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
char			*ft_itoa(long long n);
char			*ft_itoa_base(long long int n, unsigned int base);
char			*ft_itoa_ulong(unsigned long long n, unsigned int base);
void			ft_putchar(char c);
void			ft_putnbr(long long n);
void			ft_putstr(char const *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
char			*ft_strnchr(const char *s, int c, int i);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
