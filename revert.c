/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 21:03:17 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/28 21:24:37 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_li *li)
{
	int		save_first;
	int		i;
	int		len;
	int		*tmp;

	ft_putstr("ra\n");
	len = 0;
	save_first = li->tab_a[0];
	tmp = (int *)malloc(li->len_a * sizeof(tmp));
	i = 1;
	len = 0;
	while (i < li->len_a)
		tmp[len++] = li->tab_a[i++];
	tmp[len] = save_first;
	free(li->tab_a);
	li->tab_a = tmp;
}

void	rb(t_li *li)
{
	int		save_first;
	int		i;
	int		len;
	int		*tmp;

	ft_putstr("rb\n");
	if (li->len_b == 0)
		return ;
	save_first = li->tab_b[0];
	tmp = (int *)malloc((li->len_b + 1) * sizeof(tmp));
	i = 1;
	len = 0;
	while (i <= li->len_b)
		tmp[len++] = li->tab_b[i++];
	tmp[len] = save_first;
	free(li->tab_b);
	li->tab_b = tmp;
}

void	rra(t_li *li)
{
	int		save_last;
	int		i;
	int		k;
	int		*tmp;

	ft_putstr("rra\n");
	save_last = li->tab_a[li->len_a - 1];
	tmp = (int *)malloc(li->len_a * sizeof(tmp));
	tmp[0] = save_last;
	i = 0;
	k = 1;
	while (i + 1 < li->len_a)
	{
		tmp[k] = li->tab_a[i];
		k++;
		i++;
	}
	free(li->tab_a);
	li->tab_a = tmp;
}

void	rrb(t_li *li)
{
	int		save_last;
	int		i;
	int		k;
	int		*tmp;

	ft_putstr("rrb\n");
	save_last = li->tab_b[li->len_b - 1];
	tmp = (int *)malloc(li->len_b * sizeof(tmp));
	tmp[0] = save_last;
	i = 0;
	k = 1;
	while (i + 1 < li->len_b)
	{
		tmp[k] = li->tab_b[i];
		k++;
		i++;
	}
	free(li->tab_b);
	li->tab_b = tmp;
}
