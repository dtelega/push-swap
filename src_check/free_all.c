/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 13:40:11 by dtelega           #+#    #+#             */
/*   Updated: 2017/06/29 16:49:25 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	inv_cmd(t_data *d, char *s)
{
	ft_putstr_fd("Error\n", 2);
	free(s);
	free_all(d);
	sleep(10);
	exit(0);
}

void	free_all(t_data *d)
{
	free(d->cmd);
	free(d->tab_a);
	free(d->tab_b);
	free(d);
}

void	del_first_int_a(t_data *d)
{
	int		i;
	int		k;
	int		*tmp;

	i = 0;
	k = 1;
	tmp = (int *)malloc((d->ac - 1) * sizeof(tmp));
	while (k < d->len_a)
	{
		tmp[i] = d->tab_a[k];
		i++;
		k++;
	}
	free(d->tab_a);
	d->tab_a = tmp;
	d->len_a--;
}

void	del_first_int_b(t_data *d)
{
	int		i;
	int		k;
	int		*tmp;

	i = 0;
	k = 1;
	tmp = (int *)malloc((d->ac - 1) * sizeof(tmp));
	while (k < d->len_b)
	{
		tmp[i] = d->tab_b[k];
		i++;
		k++;
	}
	free(d->tab_b);
	d->tab_b = tmp;
	d->len_b--;
}
