/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:07:54 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/27 22:42:15 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

int		extra_operator(char *buffer);
int		check_args(char **args);
int		strange_character(char *buffer);
int		check_dup_ints(char *buffer);
int		check_overflow(char *buffer);

int		count_args(char **args);
char	*set_buffer(char **args);
void	ft_free_array(char **strs);
void	ft_perror(char *msg);

#endif