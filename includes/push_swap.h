/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:07:54 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/28 22:40:56 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

typedef struct t_position
{
	int top;
	int bot;
} t_position;

typedef struct t_stack_a
{
	int				number;
	int				index;
	struct t_stack_a	*next;
}	t_stack_a;

int			extra_operator(char *buffer);
int			check_args(char **args);
int			strange_character(char *buffer);
int			check_dup_ints(char *buffer);
int			check_overflow(char *buffer);

int			count_args(char **args);
char		*set_buffer(char **args);
void		ft_free_array(char **strs);
void		ft_perror(char *msg);

t_stack_a	*ft_lstnew(int content);
t_stack_a	*ft_lstlast(t_stack_a *lst);
void		ft_lstadd_back(t_stack_a **lst, t_stack_a *new);
void		ft_lstclear(t_stack_a **lst);
int			ft_lstsize(t_stack_a *lst);
void		ft_lstdelone(t_stack_a **lst);
void		ft_lstadd_front(t_stack_a **lst, t_stack_a **new);
void		lstrotate(t_stack_a **lst);
void		lstreverserotate(t_stack_a **lst);
void    	lstswap(t_stack_a **stack);

t_stack_a	*set_stack_a(char *nums);
int 		stack_sorted(t_stack_a *args);
void		index_stack(t_stack_a *args);
void 		print_stack(t_stack_a *stack);
int			find_max(t_stack_a **a);
int			find_min(t_stack_a **a);
t_position  find_position(t_stack_a **a, int index);
int 		find_min_top(t_stack_a **a, int chunk);
int 		find_min_bot(t_stack_a **a, int chunk);
int 		find_max_b(t_stack_a **b);


void 		__swap__(t_stack_a **stack, char c);
void    	__push__(t_stack_a **stack_a, t_stack_a **stack_b, char c);
void		__rotate__(t_stack_a **stack, char c);
void		__reverse_rotate__(t_stack_a **stack, char c);
void	__rr__(t_stack_a **stack_a, t_stack_a **stack_b);

void    	three_algo(t_stack_a **stack);
void    	small_algo(t_stack_a **a, t_stack_a **b);
void		big_algo(t_stack_a **a, t_stack_a **b);

#endif