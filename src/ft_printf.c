/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 08:29:21 by vgallois          #+#    #+#             */
/*   Updated: 2019/12/09 12:33:54 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf_handle(char **s, va_list *arg)
{
	int		res;
	t_pf	pf;
	t_funct	f;

	res = 0;
	(*s)++;
	if (!**s)
		return (0);
	ft_bzero(&pf, sizeof(pf));
	ft_printf_parse_flag(s, &pf);
	ft_printf_parse_width(s, &pf, arg);
	ft_printf_parse_prec(s, &pf, arg);
	if ((f = ft_printf_get_funct(**s)))
	{
		res = f(arg, &pf);
		(*s)++;
	}
	return (res);
}

static int	printrec(char *s, va_list *arg, int res)
{
	char	*tmp;

	tmp = s;
	while (*tmp && *tmp != '%')
		tmp++;
	if (!*tmp)
	{
		write(1, s, tmp - s);
		return (res + tmp - s);
	}
	write(1, s, tmp - s);
	res += tmp - s;
	res += ft_printf_handle(&tmp, arg);
	return (printrec(tmp, arg, res));
}

int			ft_printf(const char *s, ...)
{
	va_list	arg;
	int		res;

	va_start(arg, s);
	res = printrec((char *)s, &arg, 0);
	va_end(arg);
	return (res);
}
