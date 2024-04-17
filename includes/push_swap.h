/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:07:54 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/16 20:30:53 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

typedef struct t_stack_a
{
	int				number;
	int				index;
	struct t_stack_a	*next;
}	t_stack_a;

typedef struct doubly
{
    struct doubly *prev;
    int   num;
    struct doubly *next;
} doubly;

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
void		ft_lstclear(t_stack_a *lst);
int			ft_lstsize(t_stack_a *lst);

t_stack_a	*set_stack_a(char *nums);
int 		stack_sorted(t_stack_a *args);
void		index_stack(t_stack_a *args);

#endif