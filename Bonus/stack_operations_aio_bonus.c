/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_aio.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:10:34 by kael-ala          #+#    #+#             */
/*   Updated: 2024/05/08 05:48:42 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include "../includes/ft_printf.h"
#include "../includes/get_next_line.h"

void	__ss__(t_stack_a **stack_a, t_stack_a **stack_b)
{
	lstswap(stack_a);
	lstswap(stack_b);
	ft_printf("ss\n");
}

void	__rr__(t_stack_a **stack_a, t_stack_a **stack_b)
{
	lstrotate(stack_a);
	lstrotate(stack_b);
	ft_printf("rr\n");
}

void	__rrr__(t_stack_a **stack_a, t_stack_a **stack_b)
{
	lstreverserotate(stack_a);
	lstreverserotate(stack_b);
	ft_printf("rrr\n");
}
