/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:32:14 by kael-ala          #+#    #+#             */
/*   Updated: 2024/05/03 14:18:52 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"
#include "./includes/ft_printf.h"

void	__swap__(t_stack_a **stack, char c)
{
	lstswap(stack);
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
}

void	__push__(t_stack_a **stack_a, t_stack_a **stack_b, char c)
{
	ft_lstadd_front(stack_a, stack_b);
	if (c == 'a')
		ft_printf("pa\n");
	if (c == 'b')
		ft_printf("pb\n");
}

void	__rotate__(t_stack_a **stack, char c)
{
	lstrotate(stack);
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
}

void	__reverse_rotate__(t_stack_a **stack, char c)
{
	lstreverserotate(stack);
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}
