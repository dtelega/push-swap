/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:52:49 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/01 18:37:33 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_int(t_li *li)
{
	int		i;

	i = 0;
	if (!li->len_a)
		return ;
	li->min_int = li->tab_a[0];
	while (i != li->len_a)
	{
		if (li->min_int > li->tab_a[i])
			li->min_int = li->tab_a[i];
		i++;
	}
}

void	sa_sb(t_li *li, char znak)
{
	int		tmp;

	if (znak == 'a')
	{
		if (li->bonus_v == 0)
			ft_putstr("sa\n");
		else
			ft_putstr("\e[1;41msa\e[0m\n");
		tmp = li->tab_a[0];
		li->tab_a[0] = li->tab_a[1];
		li->tab_a[1] = tmp;
	}
	else if (znak == 'b')
	{
		if (li->bonus_v == 0)
			ft_putstr("sb\n");
		else
			ft_putstr("\e[1;41msb\e[0m\n");
		tmp = li->tab_b[0];
		li->tab_b[0] = li->tab_b[1];
		li->tab_b[1] = tmp;
	}
}

void	pa(t_li *li)
{
	int		*temp;
	int		i;
	int		l;

	if (li->bonus_v == 0)
		ft_putstr("pa\n");
	else
		ft_putstr("\e[1;41mpa\e[0m\n");
	temp = (int *)malloc(li->ac * sizeof(temp));
	temp[0] = li->tab_b[0];
	del_first_int_b(li);
	i = 0;
	l = 1;
	while (i < li->len_a)
	{
		temp[l] = li->tab_a[i];
		i++;
		l++;
	}
	free(li->tab_a);
	li->tab_a = temp;
	li->len_a++;
}

void	pb(t_li *li)
{
	int		*temp;
	int		i;
	int		l;

	if (li->bonus_v == 0)
		ft_putstr("pb\n");
	else
		ft_putstr("\e[1;41mpb\e[0m\n");
	temp = (int *)malloc(li->ac * sizeof(temp));
	temp[0] = li->tab_a[0];
	del_first_int_a(li);
	i = 0;
	l = 1;
	while (i < li->len_b)
	{
		temp[l] = li->tab_b[i];
		i++;
		l++;
	}
	free(li->tab_b);
	li->tab_b = temp;
	li->len_b++;
}
