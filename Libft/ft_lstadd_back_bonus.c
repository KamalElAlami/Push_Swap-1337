/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_Bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:38:27 by kael-ala          #+#    #+#             */
/*   Updated: 2023/11/22 21:11:48 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
	return ;
}
