/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_aio_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:10:34 by kael-ala          #+#    #+#             */
/*   Updated: 2024/05/10 16:22:37 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap_bonus.h"

void	__ss__(t_stack_a **stack_a, t_stack_a **stack_b)
{
	lstswap(stack_a);
	lstswap(stack_b);
}

void	__rr__(t_stack_a **stack_a, t_stack_a **stack_b)
{
	lstrotate(stack_a);
	lstrotate(stack_b);
}

void	__rrr__(t_stack_a **stack_a, t_stack_a **stack_b)
{
	lstreverserotate(stack_a);
	lstreverserotate(stack_b);
}
