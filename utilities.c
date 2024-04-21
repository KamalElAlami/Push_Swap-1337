/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:59:21 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/21 04:08:49 by kael-ala         ###   ########.fr       */
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
            prelast = (*lst)->next;
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