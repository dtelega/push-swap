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

#include "checker.h"

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
