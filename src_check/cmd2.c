/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:35:34 by dtelega           #+#    #+#             */
/*   Updated: 2017/06/29 14:35:35 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_data *d)
{
	int		save_first;
	int		i;
	int		len;
	int		*tmp;

	len = 0;
	save_first = d->tab_a[0];
	tmp = (int *)malloc(d->len_a * sizeof(tmp));
	i = 1;
	len = 0;
	while (i < d->len_a)
		tmp[len++] = d->tab_a[i++];
	tmp[len] = save_first;
	free(d->tab_a);
	d->tab_a = tmp;
}

void	rb(t_data *d)
{
	int		save_first;
	int		i;
	int		len;
	int		*tmp;

	len = 0;
	save_first = d->tab_b[0];
	tmp = (int *)malloc(d->len_b * sizeof(tmp));
	i = 1;
	len = 0;
	while (i < d->len_b)
		tmp[len++] = d->tab_b[i++];
	tmp[len] = save_first;
	free(d->tab_b);
	d->tab_b = tmp;
}

void	rr(t_data *d)
{
	ra(d);
	rb(d);
}
