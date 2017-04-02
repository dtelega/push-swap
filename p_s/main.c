/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:21:25 by dtelega           #+#    #+#             */
/*   Updated: 2017/04/01 17:37:49 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_max_first(t_li *li)
{
	int		i_max;

	i_max = 0;
	while (li->tab_b[i_max] != li->max_i_b)
		i_max++;
	if (i_max < li->len_b / 2)
		rb(li);
	else
		rrb(li);
}

void	push_mid_in_b(t_li *li)
{
	int		*sort_tab;

	sort_tab = sort_a(li, li->len_a);
	if (li->len_a > 170)
		li->median = sort_tab[li->len_a / 6];
	else if (li->len_a > 100)
		li->median = sort_tab[li->len_a / 4];
	else if (li->len_a > 5)
		li->median = sort_tab[li->len_a / 3];
	else
		li->median = sort_tab[li->len_a / 2];
	while (tab_with_lower(li) == 1 && li->len_a > 2)
	{
		if (li->tab_a[0] <= li->median)
			pb(li);
		else
			ra(li);
	}
	if (li->tab_a[0] > li->tab_a[1] && li->len_a > 1)
		sa(li);
	free(sort_tab);
}

void	go_sort(t_li *li)
{
	while (li->len_a > 2)
		push_mid_in_b(li);
	while (li->len_b != 0)
	{
		find_max_int(li);
		while (li->tab_b[0] != li->max_i_b)
		{
			find_min_int(li);
			if (li->tab_b[0] == li->min_i_b && li->len_a > 2)
			{
				pa(li);
				ra(li);
			}
			if (li->tab_b[0] == li->sec_max_i_b && li->len_a > 2)
				pa(li);
			make_max_first(li);
		}
		pa(li);
		if (li->tab_a[0] > li->tab_a[1] && li->len_a > 2)
			sa(li);
	}
	find_min_int(li);
	while (li->tab_a[0] != li->min_i_a)
		make_min_first(li);
}

int		take_all_in_a(t_li *li, int ac, char **av, int i)
{
	int		c_ac;

	c_ac = 1;
	li->len_a = 0;
	li->len_b = 0;
	li->tab_a = (int *)malloc(ac * sizeof(li->tab_a));
	li->tab_b = (int *)malloc(ac * sizeof(li->tab_a));
	li->bonus_v = 0;
	li->bonus_count = 0;
	while (c_ac != ac)
	{
		li->tab_a[i] = ft_atoi(av[c_ac]);
		if (!ft_strcmp(av[c_ac], "-v"))
		{
			li->bonus_v = 1;
			li->len_a -= 1;
			i--;
		}
		else if (valid_arg(av[c_ac]) == 1)
			return (1);
		i++;
		c_ac++;
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
		if (take_all_in_a(&li, ac, av, 0) == 1)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		if (its_sort(&li) == 1)
			return (1);
		if (dublicate(&li) == 1)
			return (0);
		go_sort(&li);
		free(li.tab_a);
		free(li.tab_b);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
