/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_uint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 18:03:37 by vgallois          #+#    #+#             */
/*   Updated: 2020/02/12 01:25:23 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_stuff(t_pf *pf, unsigned int nbrlen)
{
	if (pf->got_w && !pf->right_pad && pf->zeropad)
	{
		if (pf->got_p)
			pf->prec = ft_max(pf->width, pf->prec);
		else
			pf->prec = ft_max(pf->width, nbrlen);
		pf->got_w = 0;
		pf->got_p = 1;
	}
}

static void	printstuff(t_pf *pf, uintmax_t nbr, unsigned int nbrlen,
		char *b)
{
	ft_printf_pad(nbrlen, pf->prec, b[0]);
	ft_putnbrbase(nbr, b);
}

int			ft_printf_handle_unint(uintmax_t nbr, t_pf *pf, char *prefix,
		char *b)
{
	unsigned int	nbrlen;
	unsigned int	strlen;

	if (pf->got_p)
		pf->zeropad = 0;
	nbrlen = ft_printf_nbrlen(nbr, b);
	do_stuff(pf, nbrlen);
	strlen = ft_printf_nbrstrlen(nbr, b, prefix, pf);
	if (pf->got_w && !pf->right_pad)
		ft_printf_pad(strlen, pf->width, ' ');
	if (prefix)
	{
		ft_putstr(prefix);
		if (pf->zeropad && pf->width && (unsigned int)pf->width > nbrlen)
		{
			strlen -= ft_strlen(prefix);
			nbrlen += ft_strlen(prefix);
		}
	}
	if (strlen && !(!nbr && pf->got_p && !pf->prec))
		printstuff(pf, nbr, nbrlen, b);
	if (pf->got_w && pf->right_pad)
		ft_printf_pad(strlen, pf->width, ' ');
	return (pf->got_w ? ft_max(pf->width, strlen) : strlen);
}
