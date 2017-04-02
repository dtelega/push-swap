/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:00:14 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/15 14:00:26 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				temp;

	i = 0;
	j = 0;
	while (j < size - 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
}

int		its_sort(t_li *li)
{
	int		i;

	i = -1;
	if (li->len_a == 0)
		return (0);
	while (++i < li->len_a - 1)
		if (li->tab_a[i] > li->tab_a[i + 1])
			return (0);
	return (1);
}

int		its_rev_sort(t_li *li)
{
	int		i;

	i = -1;
	if (li->len_b == 0)
		return (0);
	while (++i < li->len_b - 1)
		if (li->tab_b[i] < li->tab_b[i + 1])
			return (0);
	return (1);
}

int		*sort_a(t_li *li, int count)
{
	int		*sort_tab;
	int		i;

	sort_tab = (int *)malloc(li->len_a * sizeof(sort_tab));
	i = -1;
	while (++i < count)
		sort_tab[i] = li->tab_a[i];
	sort_int_tab(sort_tab, i);
	return (sort_tab);
}

int		tab_with_lower(t_li *li)
{
	int		i;

	i = 0;
	while (i < li->len_a)
	{
		if (li->tab_a[i] < li->median)
			return (1);
		i++;
	}
	return (0);
}
