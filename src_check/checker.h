/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 13:09:34 by dtelega           #+#    #+#             */
/*   Updated: 2017/06/29 13:09:35 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

# include <stdio.h>

typedef struct   s_data
{
	int		*tab_a;
	int		*tab_b;
	int		len_a;
	int		len_b;
	int		ac;
	char	*cmd;
}				t_data;

int				get_next_line(const int fd, char **line);
int				valid_arg(char *arg);
int				take_all_in_a(t_data *d, char **av);
int				is_here(t_data *d, int len);
void			free_all(t_data *d);
char			*ft_strjoin_free(char *s1, const char *s2);
void			inv_cmd(t_data *d, char *s);
void			sa(t_data *d);
void			sb(t_data *d);
void			ss(t_data *d);
void			pa(t_data *d);
void			pb(t_data *d);
void			del_first_int_a(t_data *d);
void			del_first_int_b(t_data *d);
void			ra(t_data *d);
void			rb(t_data *d);
void			rr(t_data *d);
void			rra(t_data *d);
void			rrb(t_data *d);
void			rrr(t_data *d);

#endif