/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:32:14 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/19 23:18:38 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"
#include "./includes/ft_printf.h"

void __swap__(t_stack_a **stack, char c)
{
    int tmp;
    
	if(c == 'a')
		ft_printf("sa\n");
	if(c == 'b')
		ft_printf("sb\n");
    tmp = (*stack)->number;
    (*stack)->number = (*stack)->next->number;
    (*stack)->next->number = tmp;
	
} 
void    __push__(t_stack_a **stack_a, t_stack_a **stack_b, char c)
{
    ft_lstadd_front(stack_a, stack_b);
	ft_printf("pa\n");
	if (c == 'a')
		ft_printf("pa\n");
	if (c == 'b')
		ft_printf("pb\n");
    
}
