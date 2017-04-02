/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:04:05 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/05 16:39:24 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct		s_ch
{
	int		*tab_a;
	int		*tab_b;
	int		len_a;
	int		len_b;
	int		ac;
	int		min_int;
	char	*command;
}					t_ch;

void				del_first_int_a(t_ch *ch);
void				del_first_int_b(t_ch *ch);
void				sa(t_ch *ch);
void				pa(t_ch *ch);
void				pb(t_ch *ch);
void				ra(t_ch *ch);
void				rb(t_ch *ch);
void				rrb(t_ch *ch);
void				rra(t_ch *ch);
int					its_sort(t_ch *ch);
int					valid_arg(char *agr);

#endif
