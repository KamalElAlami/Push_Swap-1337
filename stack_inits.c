/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:06:30 by kael-ala          #+#    #+#             */
/*   Updated: 2024/05/08 03:17:32 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"
#include "./includes/ft_printf.h"

t_stack_a	*set_stack_a(char *nums)
{
	t_stack_a	*node;
	t_stack_a	*head;
	char		**numbers;
	int			i;

	numbers = ft_split(nums, ' ');
	head = NULL;
	i = 0;
	while (numbers[i])
	{
		node = ft_lstnew(ft_atoi(numbers[i]));
		ft_lstadd_back(&head, node);
		i++;
	}
	ft_free_array(numbers);
	return (head);
}

int	stack_sorted(t_stack_a *args)
{
	t_stack_a	*tmp;

	tmp = args;
	while (tmp)
	{
		if (tmp->next && tmp->number > tmp->next->number)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	find_max_b(t_stack_a **b)
{
	t_stack_a	*tmp;
	int			max;
	int			pos;
	int			max_pos;

	tmp = *b;
	max = 0;
	max_pos = 0;
	pos = 1;
	if (!*b)
		return (0);
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			max_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (max_pos);
}

int	find_max(t_stack_a **b)
{
	t_stack_a	*tmp;
	int			max;

	tmp = *b;
	max = 0;
	if (!*b)
		return (0);
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

void	chunk_size(t_stack_a **a, t_chunks *inf)
{
	inf->tmp = inf->chunk;
	if (ft_lstsize(*a) <= 100)
		inf->incre = 21;
	else if (ft_lstsize(*a) <= 250 && ft_lstsize(*a) > 100)
		inf->incre = 34;
	inf->chunk = inf->chunk + inf->incre;
	inf->mid = inf->tmp + inf->incre / 2;
}
