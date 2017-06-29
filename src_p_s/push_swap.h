/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:22:36 by dtelega           #+#    #+#             */
/*   Updated: 2017/04/01 17:33:13 by dtelega          ###   ########.fr       */
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
	int		median;
	int		median_part;
	int		min_i_a;
	int		max_i_a;
	int		min_i_b;
	int		sec_min_i_b;
	int		max_i_b;
	int		sec_max_i_b;
	int		thr_max_i_b;
	int		len_a;
	int		len_b;
	int		bonus_v;
	int		bonus_c;
	int		bonus_count;
	int		sec_max_add;
}						t_li;

int						take_all_in_a(t_li *li, int ac, char **av, int i);
void					go_sort(t_li *li);
void					push_mid_in_b(t_li *li);
void					make_max_first(t_li *li);
int						tab_with_lower(t_li *li);
int						*sort_a(t_li *li, int count);
int						its_rev_sort(t_li *li);
int						its_sort(t_li *li);
void					sort_int_tab(int *tab, unsigned int size);
void					make_min_first(t_li *li);
void					find_min_int(t_li *li);
void					find_max_int(t_li *li);
void					ra(t_li *li);
void					rb(t_li *li);
void					rra(t_li *li);
void					rrb(t_li *li);
void					sa(t_li *li);
void					pa(t_li *li);
void					pb(t_li *li);
void					del_first_int_a(t_li *li);
void					del_first_int_b(t_li *li);
void					get_debug(t_li *li);
int						dublicate(t_li *li);
int						valid_arg(char *arg);

#endif
