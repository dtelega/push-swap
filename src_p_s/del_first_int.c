/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_first_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:49:30 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/28 20:51:46 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_first_int_a(t_li *li)
{
	int		i;
	int		k;
	int		*tmp;

	i = 0;
	k = 1;
	tmp = (int *)malloc(li->ac * sizeof(tmp));
	while (k < li->len_a)
	{
		tmp[i] = li->tab_a[k];
		i++;
		k++;
	}
	free(li->tab_a);
	li->tab_a = tmp;
	li->len_a--;
}

void	del_first_int_b(t_li *li)
{
	int		i;
	int		k;
	int		*tmp;

	i = 0;
	k = 1;
	tmp = (int *)malloc(li->ac * sizeof(tmp));
	while (k < li->len_b)
	{
		tmp[i] = li->tab_b[k];
		i++;
		k++;
	}
	free(li->tab_b);
	li->tab_b = tmp;
	li->len_b--;
}
