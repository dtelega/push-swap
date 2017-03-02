/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:21:25 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/01 19:41:05 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		its_sort(t_li *li)
{
	int		i;

	i = 0;
	if (li->len_a == 0)
		return (0);
	while (i < li->len_a - 1)
	{
		if (li->tab_a[i] > li->tab_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		its_rev_sort(t_li *li)
{
	int		i;

	i = 0;
	if (li->len_b == 0)
		return (0);
	while (i < li->len_b - 1)
	{
		if (li->tab_b[i] < li->tab_b[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	go_sort(t_li *li)
{
	if (li->bonus_v == 1)
		get_debug(li);
	if (li->tab_a[0] > li->tab_a[1] && li->len_a > 1)
	{
		sa_sb(li, 'a');
		if (li->bonus_v == 1)
			get_debug(li);
	}
	find_min_int(li);
	while (li->tab_a[0] != li->min_int && li->len_a > 0)
	{
		make_min_first(li);
		if (li->bonus_v == 1)
			get_debug(li);
	}
	while (its_sort(li) == 1 && its_rev_sort(li) == 1 && li->len_b > 0)
	{
		pa(li);
		if (li->bonus_v == 1)
			get_debug(li);
	}
	if (its_sort(li) == 1 && li->len_b == 0)
		return ;
	pb(li);
	go_sort(li);
}

int		take_all_in_a(t_li *li, int ac, char **av)
{
	int		c_ac;
	int		i;

	i = 0;
	c_ac = 1;
	li->len_a = 0;
	li->len_b = 0;
	li->tab_a = (int *)malloc(ac * sizeof(li->tab_a));
	li->tab_b = (int *)malloc(ac * sizeof(li->tab_a));
	li->bonus_v = 0;
	while (c_ac != ac)
	{
		if (!ft_strcmp(av[c_ac], "-v"))
		{
			li->bonus_v = 1;
			li->len_a -= 1;
			i--;
		}
		else if (!(li->tab_a[i] = ft_atoi(av[c_ac])) && av[c_ac][0] != 48)
			return (1);
		c_ac++;
		i++;
		li->len_a++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_li		li;

	ft_bzero(&li, sizeof(t_li));
	if (ac >= 2)
	{
		li.tab_a = NULL;
		li.tab_b = NULL;
		li.ac = ac;
		if (take_all_in_a(&li, ac, av) == 1)
		{
			ft_putstr("Error\n");
			return (0);
		}
		if (its_sort(&li) == 1)
			return (1);
		go_sort(&li);
	}
	else
	{
		ft_putstr("1Error\n");
		exit(1);
	}
	free(li.tab_a);
	free(li.tab_b);
	return (0);
}
