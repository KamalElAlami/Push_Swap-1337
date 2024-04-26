/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:59:21 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/26 09:02:03 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"
#include "./includes/ft_printf.h"

void	lstrotate(t_stack_a **lst)
{
	t_stack_a	*tmp;
    t_stack_a   *new;

    new = *lst;
    *lst = (*lst)->next;
	if (!lst)
		return ;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
        new->next = NULL;
	}
	return ;
}

void	lstreverserotate(t_stack_a **lst)
{
	t_stack_a	*tmp;
    t_stack_a   *prelast;
    int         len;
    int i = 1;
    
    prelast = *lst;
    len = ft_lstsize(*lst) - 1;
	if (!lst || !*lst)
		return ;
	else
	{
		tmp = ft_lstlast(*lst);
        while (i++ < len )
            prelast = prelast->next;
        prelast->next = NULL;
        tmp->next = *lst;
        *lst = tmp;
	}
	return ;
}

void    lstswap(t_stack_a **stack)
{
    int tmp;
    int itemp;
    
    tmp = (*stack)->number;
    itemp = (*stack)->index;
    (*stack)->number = (*stack)->next->number;
    (*stack)->index = (*stack)->next->index;
    (*stack)->next->number = tmp;
    (*stack)->next->index = itemp;   
}

int   find_max(t_stack_a **a)
{
    t_stack_a   *tmp;
    int         max;

    tmp = *a;
    max = (*a)->index;
        while (tmp)
    {
        if (tmp->index > max)
            max = tmp->index;
        tmp = tmp->next;
    }
    return (max);
}

int find_min_top(t_stack_a **a, int chunk)
{
    t_stack_a *tmp;
    int pos;
    
    pos = 0;
    tmp = *a;
    while (tmp)
    {
        if (tmp->index < chunk)
            break ;
        pos++;
        tmp = tmp->next;
    }
    return (pos);
}
int find_min_bot(t_stack_a **a, int chunk)
{
    t_stack_a *tmp;
    int pos;
    int index_pos;
    
    pos = 0;
    tmp = *a;
    index_pos = -1;

    if (chunk == 6)
    {
        while(tmp)
        {
            tmp = tmp->next;
        }
    }
    tmp = *a;
    while (tmp)
    {
        if (tmp->index < chunk)
        {
            index_pos = pos;
        }
        pos++;
        tmp = tmp->next;
    }
    if ( index_pos != -1)
        index_pos =  ft_lstsize(*a) - index_pos + 1;
    return (index_pos);
}

t_position    find_position(t_stack_a **a, int index)
{
    t_position  coord;
    int         pos;
    t_stack_a   *tmp;
    int         len;

    tmp = *a;
    pos = 0;
    len = ft_lstsize(*a);

    
    while (tmp)
    {
        if (tmp->index == index)
            break;
        pos++;
        tmp = tmp->next;
    }
    coord.top = pos;
    coord.bot = len - pos;
    return (coord);
}

int find_max_b(t_stack_a **b)
{
    t_stack_a *tmp;
    int         max;
    int         pos;

    tmp = *b;
    max = 0;
    pos = 1;
    while (tmp)
    {
        if (tmp->index > max)
            max = pos;
        pos++;
        tmp = tmp->next;
    }
    return (max);
}