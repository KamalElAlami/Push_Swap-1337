/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:41:19 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/27 04:46:57 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/libft.h"
#include "../includes/push_swap.h"

void	ft_lstadd_front(t_stack_a **lst, t_stack_a **new)
{
	t_stack_a	*tmp;

	tmp = *new;
	if (!lst || !*lst)
		return ;
	*new = *lst ;
	*lst = (*lst)->next;
	(*new)->next = tmp;
}
