/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commans_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:50:16 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/02 13:50:24 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	del_first_int_a(t_ch *ch)
{
	int		i;
	int		k;
	int		*tmp;

	i = 0;
	k = 1;
	tmp = (int *)malloc(ch->ac * sizeof(tmp));
	while (k < ch->len_a)
	{
		tmp[i] = ch->tab_a[k];
		i++;
		k++;
	}
	free(ch->tab_a);
	ch->tab_a = tmp;
	ch->len_a--;
}

void	del_first_int_b(t_ch *ch)
{
	int		i;
	int		k;
	int		*tmp;

	i = 0;
	k = 1;
	tmp = (int *)malloc(ch->ac * sizeof(tmp));
	while (k < ch->len_b)
	{
		tmp[i] = ch->tab_b[k];
		i++;
		k++;
	}
	free(ch->tab_b);
	ch->tab_b = tmp;
	ch->len_b--;
}

void	sa(t_ch *ch)
{
	int		tmp;

	tmp = ch->tab_a[0];
	ch->tab_a[0] = ch->tab_a[1];
	ch->tab_a[1] = tmp;
}

void	pa(t_ch *ch)
{
	int		*temp;
	int		i;
	int		l;

	if (ch->len_b == 0)
		return ;
	temp = (int *)malloc(ch->ac * sizeof(temp));
	temp[0] = ch->tab_b[0];
	del_first_int_b(ch);
	i = 0;
	l = 1;
	while (i < ch->len_a)
	{
		temp[l] = ch->tab_a[i];
		i++;
		l++;
	}
	free(ch->tab_a);
	ch->tab_a = temp;
	ch->len_a++;
}

void	pb(t_ch *ch)
{
	int		*temp;
	int		i;
	int		l;

	temp = (int *)malloc(ch->ac * sizeof(temp));
	temp[0] = ch->tab_a[0];
	del_first_int_a(ch);
	i = 0;
	l = 1;
	while (i < ch->len_b)
	{
		temp[l] = ch->tab_b[i];
		i++;
		l++;
	}
	free(ch->tab_b);
	ch->tab_b = temp;
	ch->len_b++;
}
