/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:20:42 by vgallois          #+#    #+#             */
/*   Updated: 2019/12/12 17:42:05 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(va_list *arg, t_pf *pf)
{
	intmax_t	i;

	i = va_arg(*arg, intmax_t);
	return (ft_printf_handle_unint(i, pf, "0x", "0123456789abcdef"));
}
