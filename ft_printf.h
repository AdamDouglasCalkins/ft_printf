/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:59:33 by acalkins          #+#    #+#             */
/*   Updated: 2019/05/07 17:52:08 by acalkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>

typedef struct		s_arg
{
	unsigned		alternate:1;
	unsigned		zero_pad:1;
	unsigned		left_pad:1;
	unsigned		blank_pos:1;
	unsigned		sign_pos:1;
	unsigned		deci_conv:1;
	unsigned		min_width;
	unsigned		precision:1;
	unsigned		precision_len;
	char			flag_len_modifier;
	char			conv_conversion;
	char			defchar;
}					t_args;

void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putnstr_fd(char const *s, size_t len, int fd);
void				ft_putnstr(char const *s, size_t len);
int					ft_print_pad(int len_res, int pad, char c);
void				ft_putnbr(int nb);
int					ft_isdigit(int n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					int_length(int n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
char				*ft_ctostr(char c, int nb);
size_t				ft_strlen(const char *str);
void				put_uprecision(t_args *s, size_t *len, char **nbr);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strrev(char *str);
char				*ft_uitobase(uintmax_t nb, unsigned int base);
char				*ft_uitooctal(uintmax_t nb, int prefix);
int					ft_countdigit(intmax_t num);
int					ft_countdigit_unsigned(uintmax_t num);
void				ft_strdel(char **as);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strjoincl(char *s1, char *s2, int free);
char				*ft_wctostr(wchar_t c);
char				*ft_strdup(const char *s1);
char				*ft_imtoa(intmax_t num);
char				*ft_uimtoa(uintmax_t num);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(char *s1, char *s2);
void				ft_bzero(void *s, size_t n);
char				*ft_uitohex(uintmax_t nb, int uppercase);
char				*ft_nwstostr(wchar_t *ws, size_t len);
char				*ft_wstostr(wchar_t *ws);
uintmax_t			ft_unsigned_from_lenght(t_args *sarg, uintmax_t nb);
intmax_t			ft_signed_from_lenght(t_args *sarg, intmax_t nb);
int					ft_print_u(char flag, t_args *sarg, va_list larg);
int					ft_print_upper_s(t_args *sarg, va_list larg);
int					ft_print_s(t_args *sarg, va_list larg);
int					ft_print_upper_c(t_args *sarg, va_list larg);
int					ft_print_c(t_args *sarg, va_list larg);
int					ft_print_upper_x(t_args *s, va_list larg);
int					ft_print_per(t_args *sarg);
int					ft_print_x(t_args *s, va_list larg);
char				*ft_get_nbstr(char flag, t_args *sarg,
						va_list larg, char *sign);
void				put_sign(char *sign, t_args *s,
						unsigned int *len, char **nbr);
void				put_precision(t_args *s, unsigned int *len,
						char **nbr, char *sign);
int					ft_print_d(char flag, t_args *sarg, va_list larg);
int					ft_print_o(char flag, t_args *sarg, va_list larg);
char				*flag_check(const char *format, int n);
int					ft_get_flags(char *flag, t_args *sarg, int n);
int					ft_get_width(char *flag, t_args *sarg,
						va_list argptr, int n);
int					ft_get_precision(char *flag, t_args *sarg,
						va_list argptr, int n);
int					ft_get_len_modifier(char *flag, t_args *sarg, int n);
void				ft_get_args(char *flag, va_list argptr, t_args *sarg);
int					ft_print_p(t_args *sarg, va_list larg);
int					inner_print(char *flag, int i, va_list argptr);
int					step_one(const char *format, int i);
int					printfer(const char *format, va_list argptr);
int					ft_printf(const char *format, ...);

#endif
