/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 09:47:10 by vgallois          #+#    #+#             */
/*   Updated: 2019/12/12 18:08:02 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_o(va_list *arg, t_pf *pf)
{
	intmax_t	d;

	d = va_arg(*arg, unsigned int);
	return (ft_printf_handle_unint(d, pf, NULL, "01234567"));
}
