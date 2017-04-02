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
			rb(ch);
		else if (ch->command[i] == 'f')
			rrb(ch);
		else if (ch->command[i] == 'g')
			rra(ch);
		i++;
	}
}

int		take_all_in_a(t_ch *ch, int ac, char **av)
{
	int		c_ac;
	int		i;

	i = 0;
	c_ac = 1;
	ch->len_a = 0;
	ch->len_b = 0;
	ch->tab_a = (int *)malloc(ac * sizeof(ch->tab_a));
	ch->tab_b = (int *)malloc(ac * sizeof(ch->tab_a));
	while (c_ac != ac)
	{
		ch->tab_a[i] = ft_atoi(av[c_ac]);
		if (valid_arg(av[c_ac]) == 1)
			return (1);
		c_ac++;
		i++;
		ch->len_a++;
	}
	return (0);
}

int		get_commands(t_ch *ch, int i)
{
	char	*buf;

	buf = NULL;
	ch->command = (char *)malloc(8000);
	while (get_next_line(0, &buf))
	{
		if (!ft_strcmp(buf, "sa"))
			ch->command[i++] = 'a';
		else if (!ft_strcmp(buf, "pa"))
			ch->command[i++] = 'b';
		else if (!ft_strcmp(buf, "pb"))
			ch->command[i++] = 'c';
		else if (!ft_strcmp(buf, "ra"))
			ch->command[i++] = 'd';
		else if (!ft_strcmp(buf, "rb"))
			ch->command[i++] = 'e';
		else if (!ft_strcmp(buf, "rrb"))
			ch->command[i++] = 'f';
		else if (!ft_strcmp(buf, "rra"))
			ch->command[i++] = 'g';
		else
			return (1);
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
		if (take_all_in_a(&ch, ac, av) == 1 || get_commands(&ch, 0) == 1)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		do_command(&ch);
		free(ch.command);
		if (its_sort(&ch) == 0 || ch.len_b != 0)
			ft_putstr("KO\n");
		else
			ft_putstr("OK\n");
		free(ch.tab_a);
		free(ch.tab_b);
	}
	return (0);
}
