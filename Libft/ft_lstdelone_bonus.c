/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_Bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:52:41 by kael-ala          #+#    #+#             */
/*   Updated: 2023/11/23 18:04:39 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del)
		return ;
	if (lst)
	{
		(del)(lst->content);
		free(lst);
	}
}
