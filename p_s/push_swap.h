/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:22:36 by dtelega           #+#    #+#             */
/*   Updated: 2017/03/02 15:33:37 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct			s_li
{
	int		*tab_a;
	int		*tab_b;
	int		ac;
	int		min_int;
	int		len_a;
	int		len_b;
	int		bonus_v;
	int		bonus_c;
}						t_li;

void					make_min_first(t_li *li);
void					find_min_int(t_li *li);
void					ra(t_li *li);
void					rb(t_li *li);
void					rra(t_li *li);
void					rrb(t_li *li);
void					sa_sb(t_li *li, char znak);
void					pa(t_li *li);
void					pb(t_li *li);
void					del_first_int_a(t_li *li);
void					del_first_int_b(t_li *li);
void					get_debug(t_li *li);

#endif
