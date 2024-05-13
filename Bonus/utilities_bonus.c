/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:59:21 by kael-ala          #+#    #+#             */
/*   Updated: 2024/05/13 03:03:36 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap_bonus.h"

void	lstrotate(t_stack_a **lst)
{
	t_stack_a	*tmp;
	t_stack_a	*new;

	if (!lst || !*lst)
		return ;
	else
	{
		new = *lst;
		*lst = (*lst)->next;
		tmp = ft_lstlast(*lst);
		tmp->next = new;
		new->next = NULL;
	}
	return ;
}

void	lstreverserotate(t_stack_a **lst)
{
	t_stack_a	*tmp;
	t_stack_a	*prelast;
	int			len;
	int			i;

	i = 1;
	if (!lst || !*lst)
		return ;
	else
	{
		prelast = *lst;
		len = ft_lstsize(*lst) - 1;
		tmp = ft_lstlast(*lst);
		while (i++ < len)
			prelast = prelast->next;
		prelast->next = NULL;
		tmp->next = *lst;
		*lst = tmp;
	}
	return ;
}

void	lstswap(t_stack_a **stack)
{
	int	tmp;
	int	itemp;

	if (!stack || !*stack)
		return ;
	else
	{
		tmp = (*stack)->number;
		itemp = (*stack)->index;
		(*stack)->number = (*stack)->next->number;
		(*stack)->index = (*stack)->next->index;
		(*stack)->next->number = tmp;
		(*stack)->next->index = itemp;
	}
}
