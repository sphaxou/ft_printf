/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 09:00:04 by vgallois          #+#    #+#             */
/*   Updated: 2020/02/12 01:26:23 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_in(char c, char *s)
{
	while (*s)
		if (c == *s++)
			return (1);
	return (0);
}

void		ft_printf_parse_flag(char **s, t_pf *pf)
{
	while (is_in(**s, "-0"))
	{
		if (**s == '0')
			pf->zeropad = 1;
		if (**s == '-')
			pf->right_pad = 1;
		(*s)++;
	}
}

void		ft_printf_parse_width(char **s, t_pf *pf, va_list *arg)
{
	while (is_in(**s, "0123456789*"))
	{
		pf->got_w = 1;
		if (**s == '*')
		{
			(*s)++;
			pf->width = va_arg(*arg, int);
			if (pf->width < 0)
			{
				pf->width *= -1;
				pf->right_pad = 1;
				pf->zeropad = 0;
			}
		}
		else
		{
			pf->width = 0;
			while (is_in(**s, "0123456789"))
				pf->width = pf->width * 10 + (*(*s)++) - '0';
		}
	}
}

void		ft_printf_parse_prec(char **s, t_pf *pf, va_list *arg)
{
	int		prec;

	if (**s == '.')
	{
		pf->got_p = 1;
		(*s)++;
		if (**s == '*')
		{
			(*s)++;
			if ((prec = va_arg(*arg, int)) >= 0)
				pf->prec = prec;
			else
				pf->got_p = 0;
		}
		else
			while (is_in(**s, "0123456789"))
				pf->prec = 10 * pf->prec + (*(*s)++) - '0';
	}
}
