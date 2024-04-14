/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:45:38 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/05 05:55:31 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int part_array(int array[], int start, int end)
{
    int j;
    int pivot;
    int i;
    
    pivot = array[end];
    i = start - 1;
    j = start;
    while (j <= end)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[j], &array[i]);
        }
        j++;
    }
    i++;
    swap(&array[i], &array[end]);
    return (i);
}


void quick_sort(int array[], int start, int end)
{
    if (start < end)
    {

        int pivot = part_array(array, start, end);
        quick_sort(array, start, pivot - 1);
        quick_sort(array, pivot + 1, end);
    }
}
void    index_stack(t_stack_a *args)
{
    int i;
    int len = ft_lstsize(args);
    int array[len + 1];
    t_stack_a *tmp;

    i = 0;
    tmp = args;
    while (tmp)
    {
        array[i] = tmp->number;
        // printf("%d\n", array[i]);
        tmp = tmp->next;
        i++;
    }
    quick_sort(array, 0, len - 1);
    int j = 0;
    while (array[j])
    {
        printf("%d\n", array[j]);
        j++;
    }
    
    // tmp = args;
    // while (tmp)
    // {
    //     i = 0;
    //     while(array[i])
    //     {
    //         if (array[i] == args->number)
    //             args->index = i;
    //         i++;
    //     }
    //     tmp = tmp->next;
    // }
    // printf("\narg num : %d \n arg index : %d \n i : %d", args->number, args->index, i);
}
