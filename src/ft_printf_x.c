/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 09:47:10 by vgallois          #+#    #+#             */
/*   Updated: 2019/12/12 17:44:03 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_x(va_list *arg, t_pf *pf)
{
	intmax_t	d;

	d = va_arg(*arg, unsigned int);
	return (ft_printf_handle_unint(d, pf, NULL, "0123456789abcdef"));
}

int		ft_printf_xx(va_list *arg, t_pf *pf)
{
	intmax_t	d;

	d = va_arg(*arg, unsigned int);
	return (ft_printf_handle_unint(d, pf, NULL, "0123456789ABCDEF"));
}
