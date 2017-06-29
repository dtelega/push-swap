/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:43:20 by dtelega           #+#    #+#             */
/*   Updated: 2017/06/29 14:43:20 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_data *d)
{
	int		save_last;
	int		i;
	int		k;
	int		*tmp;

	save_last = d->tab_a[d->len_a - 1];
	tmp = (int *)malloc(d->len_a * sizeof(tmp));
	tmp[0] = save_last;
	i = 0;
	k = 1;
	while (i + 1 < d->len_a)
	{
		tmp[k] = d->tab_a[i];
		k++;
		i++;
	}
	free(d->tab_a);
	d->tab_a = tmp;
}

void	rrb(t_data *d)
{
	int		save_last;
	int		i;
	int		k;
	int		*tmp;

	save_last = d->tab_b[d->len_b - 1];
	tmp = (int *)malloc(d->len_b * sizeof(tmp));
	tmp[0] = save_last;
	i = 0;
	k = 1;
	while (i + 1 < d->len_b)
	{
		tmp[k] = d->tab_b[i];
		k++;
		i++;
	}
	free(d->tab_b);
	d->tab_b = tmp;
}

void	rrr(t_data *d)
{
	rra(d);
	rrb(d);
}
