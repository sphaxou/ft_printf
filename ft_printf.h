/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:56:39 by vgallois          #+#    #+#             */
/*   Updated: 2019/12/10 18:44:59 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <libc.h>

typedef struct	s_pf
{
	int			got_w;
	int			got_p;
	int			width;
	int			prec;
	int			right_pad;
	int			zeropad;
}				t_pf;

typedef int		(*t_funct)(va_list *arg, t_pf *pf);
int				ft_printf(const char *s, ...);
int				ft_printf_c(va_list *arg, t_pf *pf);
int				ft_printf_s(va_list *arg, t_pf *pf);
int				ft_printf_d(va_list *arg, t_pf *pf);
int				ft_printf_u(va_list *arg, t_pf *pf);
int				ft_printf_p(va_list *arg, t_pf *pf);
int				ft_printf_o(va_list *arg, t_pf *pf);
int				ft_printf_x(va_list *arg, t_pf *pf);
int				ft_printf_xx(va_list *arg, t_pf *pf);
int				ft_printf_percent(va_list *arg, t_pf *pf);
int				ft_printf_handle_unint(uintmax_t n, t_pf *pf, char *p, char *b);
unsigned int	ft_printf_nbrlen(uintmax_t n, char *b);
unsigned int	ft_printf_nbrstrlen(uintmax_t n, char *b, char *p, t_pf *pf);
size_t			ft_strlen(char *s);
char			*ft_itoa_base(int nb, char *b);
char			*ft_uitoa_base(unsigned int nb, char *b);
char			*ft_ltoa_base(long nb, char *b);
void			ft_bzero(void *s, size_t n);
void			ft_printf_parse_flag(char **s, t_pf *pf);
void			ft_printf_parse_width(char **s, t_pf *pf, va_list *arg);
void			ft_printf_parse_prec(char **s, t_pf *pf, va_list *arg);
void			ft_printf_pad(int size, int width, char c);
t_funct			ft_printf_get_funct(char c);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
size_t			ft_putchar(char c);
size_t			ft_putstr(char *s);
void			ft_putnbrbase(intmax_t i, char *b);
#endif
