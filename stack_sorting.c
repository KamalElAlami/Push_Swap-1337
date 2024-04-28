/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:33:17 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/28 22:42:15 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"
#include "./includes/ft_printf.h"

void	three_algo(t_stack_a **stack)
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

void	small_algo(t_stack_a **a, t_stack_a **b)
{
	t_position	coord;
	int			len;
	int			min;

	len = ft_lstsize(*a);
	while (ft_lstsize(*a) > 3)
	{
		min = find_min(a);
		coord = find_position(a, min);
		if (coord.top >= coord.bot)
		{
			while ((*a)->index != min)
				__reverse_rotate__(a, 'a');
		}
		else
		{
			while ((*a)->index != min)
				__rotate__(a, 'a');
		}
		__push__(a, b, 'b');
	}
	three_algo(a);
	while (*b)
		__push__(b, a, 'a');
}

void	a_to_b(t_stack_a **a, t_stack_a **b)
{
	int		count;
	int		chunk;
	int		next_chunk;
	int		i;
	int		len;
	int		middle;

	len = ft_lstsize(*a);
	count = 0;
	i = 0;
	chunk = ft_lstsize(*a) / 5;
	next_chunk = 0;
	while (*a)
	{
		next_chunk = i * chunk;
		middle = next_chunk - (chunk / 2);
		while (count <= next_chunk && count <= len)
		{
			while (find_min_bot(a , next_chunk) != -1)
			{
				if ((*a)->index < next_chunk)
				{
					__push__(a, b, 'b');
					if ( a && *a &&  (*a)->index < middle && ft_lstsize(*b) > 2)
						__rotate__(b, 'b');
				}
				else if (a && *a &&  ft_lstsize(*a) > 1)
					__rotate__(a, 'a');
			}
			count++;
		}
		i++;
	}
}

void	b_to_a(t_stack_a **a, t_stack_a **b)
{
	int		max_pos;
	int		stack_len;
	int		len;

	while (*b)
	{
		stack_len = ft_lstsize(*b) / 2;
		max_pos = find_max_b(b);
		len = ft_lstsize(*b);
		if (stack_len == 0)
		{
			__push__(b, a, 'a');
			break ;
		}
		if (max_pos <= stack_len)
		{
			max_pos = max_pos - 1;
			while (max_pos)
			{
				__rotate__(b, 'b');
				max_pos--;
			}
			__push__(b, a, 'a');
		}
		if (max_pos > stack_len)
		{
			max_pos = len - max_pos + 1;
			while (max_pos)
			{
				__reverse_rotate__(b, 'b');
				max_pos--;
			}
			__push__(b, a, 'a');
		}
	}
}

void	big_algo(t_stack_a **a, t_stack_a **b)
{
	a_to_b(a, b);
	// b_to_a(a, b);
}
