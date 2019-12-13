/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:24:05 by vgallois          #+#    #+#             */
/*   Updated: 2019/12/03 14:33:35 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_percent(va_list *arg, t_pf *pf)
{
	(void)arg;
	if (pf->got_w && !pf->right_pad)
		ft_printf_pad(1, pf->width, pf->zeropad ? '0' : ' ');
	write(1, "%", 1);
	if (pf->got_w && pf->right_pad)
		ft_printf_pad(1, pf->width, ' ');
	return (pf->got_w ? ft_max(pf->width, 1) : 1);
}
