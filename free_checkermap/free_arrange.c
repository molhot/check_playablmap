/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arrange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:11:18 by user              #+#    #+#             */
/*   Updated: 2023/01/03 15:09:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void free_arrangement(char **map)
{
    size_t high;

    high = 0;
    while (map[high] != NULL)
    {
        free(map[high]);
        high++;
    }
    free(map[high]);
    free(map);
}