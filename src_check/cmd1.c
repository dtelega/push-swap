/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:25:03 by dtelega           #+#    #+#             */
/*   Updated: 2017/06/29 14:25:04 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_data *d)
{
	int		tmp;

	tmp = d->tab_a[0];
	d->tab_a[0] = d->tab_a[1];
	d->tab_a[1] = tmp;
}

void	sb(t_data *d)
{
	int		tmp;

	tmp = d->tab_b[0];
	d->tab_b[0] = d->tab_b[1];
	d->tab_b[1] = tmp;
}

void	ss(t_data *d)
{
	sa(d);
	sb(d);
}

void	pa(t_data *d)
{
	int		*temp;
	int		i;
	int		l;

	if (d->len_b == 0)
		return ;
	temp = (int *)malloc((d->ac - 1) * sizeof(temp));
	temp[0] = d->tab_b[0];
	del_first_int_b(d);
	i = 0;
	l = 1;
	while (i < d->len_a)
	{
		temp[l] = d->tab_a[i];
		i++;
		l++;
	}
	free(d->tab_a);
	d->tab_a = temp;
	d->len_a++;
}

void	pb(t_data *d)
{
	int		*temp;
	int		i;
	int		l;

	if (d->len_a == 0)
		return ;
	temp = (int *)malloc((d->ac - 1) * sizeof(temp));
	temp[0] = d->tab_a[0];
	del_first_int_a(d);
	i = 0;
	l = 1;
	while (i < d->len_b)
	{
		temp[l] = d->tab_b[i];
		i++;
		l++;
	}
	free(d->tab_b);
	d->tab_b = temp;
	d->len_b++;
}
