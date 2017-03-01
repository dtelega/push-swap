/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:21:25 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/28 22:07:33 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

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
	if (li->tab_a[0] > li->tab_a[1] && li->len_a > 1)
		sa_sb(li, 'a');
	find_min_int(li);
	while (li->tab_a[0] != li->min_int && li->len_a > 0)
		ra(li);
	while (its_sort(li) == 1 && its_rev_sort(li) == 1 && li->len_b > 0)
		pa(li);
	if (its_sort(li) == 1 && li->len_b == 0)
		return ;
	pb(li);
	go_sort(li);
}

int		take_all_in_a(t_li *li, int ac, char **av)
{
	int		count_ac;
	int		i;

	i = 0;
	count_ac = 1;
	li->len_a = 0;
	li->len_b = 0;
	li->tab_a = (int *)malloc(ac * sizeof(li->tab_a));
	li->tab_b = (int *)malloc(ac * sizeof(li->tab_a));
	while (count_ac != ac)
	{
		li->tab_a[i] = ft_atoi(av[count_ac]);
		count_ac++;
		i++;
		li->len_a++;
	}
	return (0);
}

int 	main(int ac, char **av)
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
		ft_putstr("Error\n");
		exit(1);
	}

// ..............................RESULT...........................
	int i = 0;
	its_sort(&li);
	printf("RESULTS :\n");
	printf("len a = %i\n", li.len_a);
	while (i < li.len_a)
	{
		printf("tab_a[%i] = %i\n", i, li.tab_a[i++]);
	//	sleep(1);
	}
	i = 0;
	while (i < li.len_b)
		printf("          tab_b[%i] = %i\n", i, li.tab_b[i++]);
//................................END.RESULT......................


	free(li.tab_a);
	free(li.tab_b);
	return (0);
}
