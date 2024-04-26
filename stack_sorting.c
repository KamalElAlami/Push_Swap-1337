/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:33:17 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/26 03:47:37 by kael-ala         ###   ########.fr       */
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
    int         len;
    int max;

    len = ft_lstsize(*a);
    while (ft_lstsize(*a) > 3)
    {
        max = find_max(a);
        coord = find_position(a, max);
        if (coord.top >= coord.bot)
        {
            while ((*a)->index != max)
                __reverse_rotate__(a, 'a');
        }
        else
        {
            while ((*a)->index != max)
                __rotate__(a, 'a');
        }
        __push__(a, b, 'b');
    }
    three_algo(a);
    while (*b)
        __push__(b, a, 'a');

    if (len == 4)
        __rotate__(a, 'a');
    else if (len == 5)
    {
        __swap__(a, 'a');
        __rotate__(a, 'a');
        __rotate__(a, 'a');
    }
}

void big_algo(t_stack_a **a, t_stack_a **b)
{
    int i;
    int chunk;
    int chunka;
    int count;
    int len;
    int position;
    int pooos;

    chunk = ft_lstsize(*a) / 5;
    count = 0;
    i = 1;
    len = ft_lstsize(*a);
    while (*a)
    {
        chunka = i * chunk;
        while (count <= chunka && count <= len)
        {
            position = find_min_top(a, chunka);
            pooos = find_min_bot(a, chunka);
            if (pooos == -1)
                break;
            if (position <= pooos)
            {
                while (position)
                {
                    __rotate__(a, 'a');
                    position--;
                }
                __push__(a, b, 'b');
            }
            else if (position > pooos)
            {
                while (pooos)
                {
                    __reverse_rotate__(a, 'a');
                    pooos--;
                }
                __push__(a, b, 'b');
            }
            count++;
        }
        i++;
    }
}
