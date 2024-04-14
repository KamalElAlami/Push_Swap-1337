/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:06:41 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/14 21:20:12 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"

int	count_args(char **args)
{
	int	count;

	count = 1;
	while (args[count])
		count++;
	return (count - 1);
}

char	*set_buffer(char **args)
{
	int		i;
	char	*buffer;
	char	*temp;

	i = 1;
	buffer = NULL;
	while (args[i])
	{
		temp = ft_strjoin(buffer, args[i]);
		free(buffer);
		buffer = temp;
		temp = ft_strjoin(buffer, " ");
		free(buffer);
		buffer = temp;
		i++;
	}
	return (buffer);
}

int	check_args(char **args)
{
	char	*buffer;

	buffer = set_buffer(args);
	if (!(extra_operator(buffer)) && !(strange_character(buffer))
		&& !(check_dup_ints(buffer)) && !(check_overflow(buffer)))
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	return (1);
}
