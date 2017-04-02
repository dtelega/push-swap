/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:56:33 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/05 14:56:34 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		valid_arg(char *arg)
{
	int			i;
	long int	nb;
	int			neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '+' && arg[i] != '-')
			return (1);
		if (arg[i] == '-')
			neg = 1;
		else if (arg[i] == '+')
			neg = 2;
		else
			nb = nb * 10 + arg[i] - '0';
		i++;
	}
	if (neg == 1)
		nb = nb * -1;
	if (nb > 2147483647 || nb < -2147483648)
		return (1);
	return (0);
}

int		dublicate(t_li *li)
{
	int		i;
	int		k;
	int		nb;

	i = 0;
	while (i < li->len_a)
	{
		k = i;
		nb = li->tab_a[i];
		while (++k < li->len_a)
		{
			if (nb == li->tab_a[k])
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
