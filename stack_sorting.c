/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:33:17 by kael-ala          #+#    #+#             */
/*   Updated: 2024/05/03 15:09:21 by kael-ala         ###   ########.fr       */
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
	int		predict_min;

	len = ft_lstsize(*a);
	count = 0;
	i = 0;
	next_chunk = 0;

	
	if (ft_lstsize(*a) >= 150)
		chunk = ft_lstsize(*a) / 8;
	else
		chunk = ft_lstsize(*a) / 5;
	while (*a)
	{
		next_chunk = i * chunk;
		middle = next_chunk - (chunk / 2);
		while (count <= next_chunk && count <= len)
		{
			while (find_min_bot(a , next_chunk) != -1)
			{
				if ((*a)->index < next_chunk)
					__push__(a, b, 'b');
				predict_min = find_min_bot(a, next_chunk);
				if (predict_min != -1 )
				{
					if (a && *a && b && *b && find_min_top(a , next_chunk) != 0 && (*a)->index >= next_chunk  &&  (*b)->index < middle  &&  (*b)->index  > (next_chunk - chunk ) &&  ft_lstsize(*b) >= 2 && ft_lstsize(*a) >= 2)
						__rr__(a , b);
					else if ((*a)->index >= next_chunk && ft_lstsize(*a) >= 2)
					{
						__rotate__(a, 'a');
					}
					else if ((*b)->index < middle &&  (*b)->index  > (next_chunk - chunk )  && ft_lstsize(*b) >= 2)
						__rotate__(b, 'b');
				}
				else
				{
					if (b && *b && (*b)->index < middle && ft_lstsize(*b) >= 2)
						__rotate__(b, 'b');
				}
			}
			count++;
		}
		i++;
	}
}

void ft_sort_top_b(t_stack_a **a, t_stack_a **b, void  operation1(t_stack_a **, char) , void  operation2(t_stack_a **, char))
{
	int		max_pos;
	int		stack_len;
	int		pre_max;
	
	stack_len = ft_lstsize(*b) / 2;
	max_pos = find_max(b);
	pre_max = find_pre_max(b);

		while((*b)->index != max_pos && (*b)->index != pre_max )
			operation1(b , 'b');
		__push__(b , a , 'a');
		if (max_pos != pre_max && ft_lstsize(*b) > 2)
		{
			while((*b)->index != max_pos && (*b)->index != pre_max )
				operation2(b , 'b');
			__push__(b , a , 'a');
		}
		else if (max_pos == pre_max && ft_lstsize(*b) == 1)
			__push__(b , a , 'a');
		if (ft_lstsize(*a) >= 2  && (*a)->index > (*a)->next->index)
			__swap__(a, 'a');
}

void	b_to_a(t_stack_a **a, t_stack_a **b)
{
	int		max_pos;
	int		stack_len;
	int		pre_max;
	int     pre_pro_max;
	

	
	while (*b)
	{
		stack_len = ft_lstsize(*b) / 2;
		max_pos = find_max(b);
		pre_max = find_pre_max(b);
		pre_pro_max = pre_max - 1;
		if (find_position(b ,pre_max).top >= stack_len   && find_position(b, max_pos).top >= stack_len )
			ft_sort_top_b(a , b , __reverse_rotate__, __reverse_rotate__);
		else if (find_position(b ,pre_max).top <= stack_len   && find_position(b, max_pos).top <= stack_len )
			ft_sort_top_b(a , b , &__rotate__, &__rotate__);
		else if (find_position(b ,max_pos).top <= stack_len   && find_position(b, pre_max).top >= stack_len )
			ft_sort_top_b(a , b , &__rotate__, &__reverse_rotate__);
		else if (find_position(b ,max_pos).top >= stack_len   && find_position(b, pre_max).top <= stack_len )
			ft_sort_top_b(a , b , &__rotate__, &__reverse_rotate__);
	}
}

void	big_algo(t_stack_a **a, t_stack_a **b)
{
	a_to_b(a, b);
	b_to_a(a, b);
}
