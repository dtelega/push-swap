/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:03:49 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/02 13:03:50 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_command(t_ch *ch)
{
	int		i;

	i = 0;
	while (ch->command[i])
	{
		if (ch->command[i] == 'a')
			sa(ch);
		else if (ch->command[i] == 'b')
			pa(ch);
		else if (ch->command[i] == 'c')
			pb(ch);
		else if (ch->command[i] == 'd')
			ra(ch);
		else if (ch->command[i] == 'e')
			rra(ch);
		i++;
	}
}

int		take_all_in_a(t_ch *ch, int ac, char **av)
{
	int		count_ac;
	int		i;

	i = 0;
	count_ac = 1;
	ch->len_a = 0;
	ch->len_b = 0;
	ch->tab_a = (int *)malloc(ac * sizeof(ch->tab_a));
	ch->tab_b = (int *)malloc(ac * sizeof(ch->tab_a));
	while (count_ac != ac)
	{
		if (!(ch->tab_a[i] = ft_atoi(av[count_ac])) && av[count_ac][0] != 48)
			return (1);
		count_ac++;
		i++;
		ch->len_a++;
	}
	return (0);
}

int		get_commands(t_ch *ch)
{
	char	*buf;
	int		i;

	i = 0;
	buf = NULL;
	ch->command = (char *)malloc(100);
	while (get_next_line(0, &buf))
	{
		if (!ft_strcmp(buf, "sa"))
			ch->command[i] = 'a';
		else if (!ft_strcmp(buf, "pa"))
			ch->command[i] = 'b';
		else if (!ft_strcmp(buf, "pb"))
			ch->command[i] = 'c';
		else if (!ft_strcmp(buf, "ra"))
			ch->command[i] = 'd';
		else if (!ft_strcmp(buf, "rra"))
			ch->command[i] = 'e';
		else
			return (1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_ch	ch;

	if (ac > 1)
	{
		ft_bzero(&ch, sizeof(t_ch));
		ch.tab_a = NULL;
		ch.tab_b = NULL;
		ch.ac = ac;
		if (take_all_in_a(&ch, ac, av) == 1 || get_commands(&ch) == 1)
		{
			ft_putstr("Error\n");
			return (0);
		}
		do_command(&ch);
		if (its_sort(&ch) == 0)
			ft_putstr("KO\n");
		else
			ft_putstr("OK\n");
	}
	free(ch.tab_a);
	return (0);
}
