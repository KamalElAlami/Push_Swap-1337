/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:59:10 by kael-ala          #+#    #+#             */
/*   Updated: 2024/05/06 23:43:50 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include "../includes/ft_printf.h"

void	ft_free_array(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	strs = NULL;
}

void	ft_perror(char *msg)
{
	ft_printf("%s", msg);
	exit(EXIT_FAILURE);
}

int	find_min_top(t_stack_a **a, int chunk)
{
	t_stack_a	*tmp;
	int			pos;

	pos = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index < chunk)
			break ;
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int	find_min_bot(t_stack_a **a, int chunk)
{
	t_stack_a	*tmp;
	int			pos;
	int			index_pos;

	pos = 0;
	tmp = *a;
	index_pos = -1;
	if (!tmp)
		return (-1);
	while (tmp)
	{
		if (tmp->index < chunk)
		{
			index_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	if (index_pos != -1)
		index_pos = ft_lstsize(*a) - index_pos + 1;
	return (index_pos);
}

t_position	find_position(t_stack_a **a, int index)
{
	t_position	coord;
	int			pos;
	t_stack_a	*tmp;
	int			len;

	tmp = *a;
	pos = 0;
	len = ft_lstsize(*a);
	while (tmp)
	{
		if (tmp->index == index)
			break ;
		pos++;
		tmp = tmp->next;
	}
	coord.top = pos;
	coord.bot = len - pos;
	return (coord);
}
