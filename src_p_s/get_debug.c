/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:35:29 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/02 14:35:30 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_debug(t_li *li)
{
	int		i;

	i = -1;
	ft_putstr("\n\e[5;32mDEBUG:\e[0m\n");
	ft_putstr("stack A(");
	ft_putnbr(li->len_a);
	ft_putstr("): ");
	while (++i < li->len_a)
	{
		ft_putstr(" ");
		ft_putnbr(li->tab_a[i]);
	}
	ft_putstr("\n");
	i = -1;
	ft_putstr("stack B(");
	ft_putnbr(li->len_b);
	ft_putstr("): ");
	while (++i < li->len_b)
	{
		ft_putstr(" ");
		ft_putnbr(li->tab_b[i]);
	}
	ft_putstr("\n\n");
	ft_putnbr(li->bonus_count);
	ft_putstr(" operations!\n\n");
}
