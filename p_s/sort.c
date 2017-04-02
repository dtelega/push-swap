/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:52:49 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/05 16:41:04 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_int(t_li *li)
{
	int		i;

	i = 0;
	if (!li->len_a)
		return ;
	li->min_i_a = li->tab_a[0];
	while (i != li->len_a)
	{
		if (li->min_i_a > li->tab_a[i])
			li->min_i_a = li->tab_a[i];
		i++;
	}
	i = -1;
	li->min_i_b = li->tab_b[0];
	li->sec_min_i_b = li->tab_b[0];
	while (++i != li->len_b)
		if (li->min_i_b > li->tab_b[i])
			li->min_i_b = li->tab_b[i];
	i = -1;
	while (++i != li->len_b)
		if (li->min_i_b > li->tab_b[i] && li->tab_b[i] > li->min_i_b)
			li->sec_min_i_b = li->tab_b[i];
}

void	find_max_int(t_li *li)
{
	int		i;

	i = -1;
	if (!li->len_a)
		return ;
	li->max_i_a = li->tab_a[0];
	while (++i != li->len_a)
		if (li->max_i_a < li->tab_a[i])
			li->max_i_a = li->tab_a[i];
	i = -1;
	li->max_i_b = li->tab_b[0];
	li->sec_max_i_b = li->tab_b[0];
	li->thr_max_i_b = li->tab_b[0];
	while (++i != li->len_b)
		if (li->max_i_b < li->tab_b[i])
			li->max_i_b = li->tab_b[i];
	i = -1;
	while (++i != li->len_b)
		if (li->sec_max_i_b < li->tab_b[i] && li->tab_b[i] != li->max_i_b)
			li->sec_max_i_b = li->tab_b[i];
	i = -1;
	while (++i != li->len_b)
		if (li->thr_max_i_b < li->tab_b[i] && li->tab_b[i] < li->sec_max_i_b)
			li->thr_max_i_b = li->tab_b[i];
}

void	sa(t_li *li)
{
	int		tmp;

	if (li->bonus_v == 0)
		ft_putstr("sa\n");
	else
		ft_putstr("\e[1;41msa\e[0m\n");
	li->bonus_count++;
	tmp = li->tab_a[0];
	li->tab_a[0] = li->tab_a[1];
	li->tab_a[1] = tmp;
}

void	pa(t_li *li)
{
	int		*temp;
	int		i;
	int		l;

	if (li->len_b == 0)
		return ;
	li->bonus_count++;
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
	li->bonus_count++;
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
