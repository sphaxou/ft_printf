/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 09:38:36 by vgallois          #+#    #+#             */
/*   Updated: 2019/12/09 12:37:47 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(va_list *arg, t_pf *pf)
{
	char	*s;
	size_t	len;

	s = va_arg(*arg, char *);
	if (!s)
		s = "(null)";
	len = pf->got_p ? ft_min(pf->prec, (int)ft_strlen(s)) : ft_strlen(s);
	if (pf->got_w && !pf->right_pad)
		ft_printf_pad(len, pf->width, pf->zeropad ? '0' : ' ');
	write(1, s, len);
	if (pf->got_w && pf->right_pad)
		ft_printf_pad(len, pf->width, ' ');
	return (pf->got_w ? ft_max((int)len, pf->width) : len);
}
