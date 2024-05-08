/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:33:17 by kael-ala          #+#    #+#             */
/*   Updated: 2024/05/08 03:09:47 by kael-ala         ###   ########.fr       */
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

void	predict_to_push(t_stack_a **a, t_stack_a **b, t_chunks inf)
{
	int		predict_min;

	predict_min = find_min_bot(a, inf.chunk);
	if (predict_min != -1)
	{
		if (*a && *b && find_min_top(a, inf.chunk) != 0
			&& (*a)->index >= inf.chunk && (*b)->index < inf.mid
			&& (*b)->index > (inf.chunk - inf.incre - 1) && ft_lstsize(*b) >= 2
			&& ft_lstsize(*a) >= 2)
			__rr__(a, b);
		else if ((*a)->index >= inf.chunk && ft_lstsize(*a) >= 2)
			__rotate__(a, 'a');
		else if ((*b)->index < inf.mid
			&& (*b)->index > (inf.chunk - inf.incre - 1) && ft_lstsize(*b) >= 2)
			__rotate__(b, 'b');
	}
	else
		if (b && *b && (*b)->index < inf.mid && ft_lstsize(*b) >= 2)
			__rotate__(b, 'b');
}

void	a_to_b(t_stack_a **a, t_stack_a **b)
{
	int			count;
	int			len;
	t_chunks	inf;

	len = ft_lstsize(*a);
	inf.incre = 57;
	inf.chunk = -1;
	while (*a)
	{
		count = 0;
		chunk_size(a, &inf);
		while (count <= inf.chunk && count <= len)
		{
			while (find_min_bot(a, inf.chunk) != -1)
			{
				if ((*a)->index < inf.chunk)
					__push__(a, b, 'b');
				predict_to_push(a, b, inf);
			}
			count++;
		}
	}
}

void	ft_sort_top_b(t_stack_a **a, t_stack_a **b,
	void operation1(t_stack_a **, char), void operation2(t_stack_a **, char))
{
	int		max_pos;
	int		pre_max;

	max_pos = find_max(b);
	pre_max = find_pre_max(b);
	while ((*b)->index != max_pos && (*b)->index != pre_max)
		operation1(b, 'b');
	__push__(b, a, 'a');
	if (max_pos != pre_max && ft_lstsize(*b) > 2)
	{
		while ((*b)->index != max_pos && (*b)->index != pre_max)
			operation2(b, 'b');
		__push__(b, a, 'a');
	}
	else if (max_pos == pre_max && ft_lstsize(*b) == 1)
		__push__(b, a, 'a');
	if (ft_lstsize(*a) >= 2 && (*a)->index > (*a)->next->index)
		__swap__(a, 'a');
}

void	b_to_a(t_stack_a **a, t_stack_a **b)
{
	int		max_pos;
	int		stack_len;
	int		pre_max;

	while (*b)
	{
		stack_len = ft_lstsize(*b) / 2;
		max_pos = find_max(b);
		pre_max = find_pre_max(b);
		if (find_position(b, pre_max).top >= stack_len
			&& find_position(b, max_pos).top >= stack_len)
			ft_sort_top_b(a, b, __reverse_rotate__, __reverse_rotate__);
		else if (find_position(b, pre_max).top <= stack_len
			&& find_position(b, max_pos).top <= stack_len)
			ft_sort_top_b(a, b, &__rotate__, &__rotate__);
		else if (find_position(b, max_pos).top <= stack_len
			&& find_position(b, pre_max).top >= stack_len)
			ft_sort_top_b(a, b, &__rotate__, &__reverse_rotate__);
		else if (find_position(b, max_pos).top >= stack_len
			&& find_position(b, pre_max).top <= stack_len)
			ft_sort_top_b(a, b, &__rotate__, &__reverse_rotate__);
	}
}
