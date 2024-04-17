/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:32:14 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/17 16:23:16 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"
#include "./includes/ft_printf.h"

void swap_it(t_stack_a **stack, char c)
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

void    push_it(t_stack_a **stack_src, t_stack_a **stack_dest, char c)
{
    if(c == 'a')
		ft_printf("pa\n");
	if(c == 'b')
		ft_printf("pb\n");
        
}
