/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:06:30 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/27 04:45:44 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"

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
