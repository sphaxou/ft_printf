/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 07:42:59 by vgallois          #+#    #+#             */
/*   Updated: 2019/12/10 18:44:21 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libc.h>

void			ft_putnbrbase(intmax_t nb, char *b)
{
	int	blen;

	blen = (int)ft_strlen(b);
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb <= -blen)
			ft_putnbrbase((nb / -blen), b);
		ft_putchar(b[-(nb % blen)]);
	}
	else
	{
		if (nb >= blen)
			ft_putnbrbase(nb / blen, b);
		ft_putchar(b[nb % blen]);
	}
}
