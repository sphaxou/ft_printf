/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:24:51 by vgallois          #+#    #+#             */
/*   Updated: 2019/12/12 18:11:38 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_printf_nbrlen(uintmax_t n, char *b)
{
	unsigned int	i;
	size_t			strlen;

	i = 0;
	strlen = ft_strlen(b);
	if (!n)
		return (1);
	while (n)
	{
		n /= strlen;
		i++;
	}
	return (i);
}

unsigned int	ft_printf_nbrstrlen(uintmax_t n, char *b,
		char *prefix, t_pf *pf)
{
	unsigned int	nbrlen;
	unsigned int	strlen;

	nbrlen = ft_printf_nbrlen(n, b);
	if (!n && pf->got_p && !pf->prec)
		strlen = 0;
	else if (pf->got_p)
		strlen = ft_max(nbrlen, pf->prec);
	else
		strlen = nbrlen;
	if (prefix)
		strlen += ft_strlen(prefix);
	return (strlen);
}
