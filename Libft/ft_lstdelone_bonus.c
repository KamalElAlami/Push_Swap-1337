/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:52:41 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/27 04:47:55 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstdelone(t_stack_a **lst)
{
	t_stack_a	*tmp;

	tmp = *lst;
	if (!*lst)
		return ;
	*lst = (*lst)->next;
	free(tmp);
}
