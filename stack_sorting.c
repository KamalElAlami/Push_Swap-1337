/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:33:17 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/22 05:27:02 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./includes/libft.h"
#include "./includes/push_swap.h"
#include "./includes/ft_printf.h"

void    three_algo(t_stack_a **stack)
{
    if ((*stack)->number > (*stack)->next->number
        && (*stack)->next->number < (*stack)->next->next->number
        && (*stack)->number < (*stack)->next->next->number)
        __swap__(stack, 'a');
    else if ((*stack)->number > (*stack)->next->number
        && (*stack)->next->number > (*stack)->next->next->number
        && (*stack)->number > (*stack)->next->next->number)
    {
        __swap__(stack, 'a');
        __reverse_rotate__(stack, 'a');
    }
    else if ((*stack)->number > (*stack)->next->number
        && (*stack)->next->number < (*stack)->next->next->number
        && (*stack)->number > (*stack)->next->next->number)
        __rotate__(stack, 'a');
    else if ((*stack)->number < (*stack)->next->number
        && (*stack)->next->number > (*stack)->next->next->number
        && (*stack)->number < (*stack)->next->next->number)
    {
        __swap__(stack, 'a');
        __rotate__(stack, 'a');
    }
    else if ((*stack)->number < (*stack)->next->number
        && (*stack)->next->number > (*stack)->next->next->number
        && (*stack)->number > (*stack)->next->next->number)
        __reverse_rotate__(stack, 'a');
}

void    small_algo(t_stack_a **a, t_stack_a **b)
{
    t_position coord;
    // t_stack_a *tmp;
    int max;

    // tmp = *a;
    while (ft_lstsize(*a) > 3)
    {
        
        max = find_max(a);
        coord = find_position(a, max);
        if (coord.top >= coord.bot)
        {
            while ((*a)->index != max)
            {
                printf( "max  %d\n  index  %d\n " , max, (*a)->index);
                __reverse_rotate__(a, 'a');
            }
                // tmp = tmp->next;
        }
        else
        {
            while ((*a)->index != max)
                __rotate__(a, 'a');
        }
        __push__(a, b, 'b');
        print_stack(*b);
        exit(0);
    }
    three_algo(a);
    while (*b)
        __push__(b, a, 'a');
    __rotate__(a, 'a');
    // __rotate__(a, 'a');
}