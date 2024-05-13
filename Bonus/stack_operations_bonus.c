/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:32:14 by kael-ala          #+#    #+#             */
/*   Updated: 2024/05/12 21:00:41 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	__swap__(t_stack_a **stack)
{
	lstswap(stack);
}

void	__push__(t_stack_a **stack_a, t_stack_a **stack_b)
{
	ft_lstadd_front(stack_a, stack_b);
}

void	__rotate__(t_stack_a **stack)
{
	lstrotate(stack);
}

void	__reverse_rotate__(t_stack_a **stack)
{
	lstreverserotate(stack);
}
