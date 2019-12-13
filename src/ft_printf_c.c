/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 09:29:19 by vgallois          #+#    #+#             */
/*   Updated: 2019/12/09 11:47:45 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_c(va_list *arg, t_pf *pf)
{
	char	c;

	if (pf->got_w && !pf->right_pad)
		ft_printf_pad(1, pf->width, pf->zeropad ? '0' : ' ');
	c = va_arg(*arg, int);
	write(1, &c, 1);
	if (pf->got_w && pf->right_pad)
		ft_printf_pad(1, pf->width, ' ');
	return (pf->got_w ? MAX(pf->width, 1) : 1);
}
