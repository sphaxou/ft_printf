/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 09:47:10 by vgallois          #+#    #+#             */
/*   Updated: 2019/12/10 18:37:24 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_d(va_list *arg, t_pf *pf)
{
	intmax_t	d;
	char		*p;

	p = NULL;
	d = va_arg(*arg, int);
	if (d < 0)
	{
		d = -d;
		p = "-";
	}
	return (ft_printf_handle_unint(d, pf, p, "0123456789"));
}
