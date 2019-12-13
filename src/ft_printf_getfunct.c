/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getfunct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 08:54:28 by vgallois          #+#    #+#             */
/*   Updated: 2019/12/09 12:42:24 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	create_tab(t_funct *tab)
{
	tab['c'] = ft_printf_c;
	tab['d'] = ft_printf_d;
	tab['i'] = ft_printf_d;
	tab['s'] = ft_printf_s;
	tab['p'] = ft_printf_p;
	tab['u'] = ft_printf_u;
	tab['o'] = ft_printf_o;
	tab['x'] = ft_printf_x;
	tab['X'] = ft_printf_xx;
	tab['%'] = ft_printf_percent;
}

t_funct		ft_printf_get_funct(char c)
{
	static t_funct	*tab = NULL;

	if (!tab)
	{
		if (!(tab = malloc(sizeof(t_funct) * 256)))
			return (NULL);
		ft_bzero(tab, sizeof(*tab) * 256);
		create_tab(tab);
	}
	return (tab[(int)c]);
}
