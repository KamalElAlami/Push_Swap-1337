/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 01:20:13 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/27 04:46:16 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	ft_lstsize(t_stack_a *lst)
{
	int			count;
	t_stack_a	*tmp;

	count = 0;
	tmp = lst;
	if (!lst)
		return (0);
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
