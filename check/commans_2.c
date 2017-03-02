/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commans_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:55:36 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/02 13:55:48 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_ch *ch)
{
	int		save_first;
	int		i;
	int		len;
	int		*tmp;

	len = 0;
	save_first = ch->tab_a[0];
	tmp = (int *)malloc(ch->len_a * sizeof(tmp));
	i = 1;
	len = 0;
	while (i < ch->len_a)
		tmp[len++] = ch->tab_a[i++];
	tmp[len] = save_first;
	free(ch->tab_a);
	ch->tab_a = tmp;
}

void	rra(t_ch *ch)
{
	int		save_last;
	int		i;
	int		k;
	int		*tmp;

	save_last = ch->tab_a[ch->len_a - 1];
	tmp = (int *)malloc(ch->len_a * sizeof(tmp));
	tmp[0] = save_last;
	i = 0;
	k = 1;
	while (i + 1 < ch->len_a)
	{
		tmp[k] = ch->tab_a[i];
		k++;
		i++;
	}
	free(ch->tab_a);
	ch->tab_a = tmp;
}

int		its_sort(t_ch *ch)
{
	int		i;

	i = 0;
	if (ch->len_a == 0)
		return (0);
	while (i < ch->len_a - 1)
	{
		if (ch->tab_a[i] > ch->tab_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
