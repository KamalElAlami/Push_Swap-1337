/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:20:47 by kael-ala          #+#    #+#             */
/*   Updated: 2024/05/13 03:08:55 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"
#include "../includes/ft_printf.h"

int	check_op(char *buffer, t_stack_a **a, t_stack_a **b)
{
	if (ft_strcmp(buffer, "sa\n") == 0)
		return (__swap__(a), 0);
	else if (ft_strcmp(buffer, "sb\n") == 0)
		return (__swap__(b), 0);
	else if (ft_strcmp(buffer, "pb\n") == 0)
		return (__push__(a, b), 0);
	else if (ft_strcmp(buffer, "pa\n") == 0)
		return (__push__(b, a), 0);
	else if (ft_strcmp(buffer, "ss\n") == 0)
		return (__ss__(a, b), 0);
	else if (ft_strcmp(buffer, "ra\n") == 0)
		return (__rotate__(a), 0);
	else if (ft_strcmp(buffer, "rb\n") == 0)
		return (__rotate__(b), 0);
	else if (ft_strcmp(buffer, "rr\n") == 0)
		return (__rr__(a, b), 0);
	else if (ft_strcmp(buffer, "rra\n") == 0)
		return (__reverse_rotate__(a), 0);
	else if (ft_strcmp(buffer, "rrb\n") == 0)
		return (__reverse_rotate__(b), 0);
	else if (ft_strcmp(buffer, "rrr\n") == 0)
		return (__rrr__(a, b), 0);
	return (1);
}
