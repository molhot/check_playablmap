/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:50:22 by user              #+#    #+#             */
/*   Updated: 2023/01/02 18:48:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    fill_repeat(char **map_copy, int high, int row)
{
    int i = 0;

    while (map_copy[i] != NULL)
    {
        printf("%s\n", map_copy[i]);
        i++;
    }
    printf("----------\n");
    if (map_copy[high][row] != 'P')
        map_copy[high][row] = 'X';
    if (map_copy[high + 1][row] != '1' && map_copy[high + 1][row] != 'X')
        fill_repeat(map_copy, high + 1, row);
    if (map_copy[high - 1][row] != '1' &&  map_copy[high - 1][row] != 'X')
        fill_repeat(map_copy, high - 1, row);
    if (map_copy[high][row + 1] != '1' &&  map_copy[high][row + 1] != 'X')
        fill_repeat(map_copy, high, row + 1);
    if (map_copy[high][row - 1] != '1' &&  map_copy[high][row - 1] != 'X')
        fill_repeat(map_copy, high, row - 1);
    if (map_copy[high + 1][row] == '1' || map_copy[high - 1][row] == '1' || map_copy[high][row + 1] == '1' || map_copy[high][row - 1] == '1')
    {
        printf("return\n");
        return ;
    }
}

bool    fill_check(char **mapinfo, int position)
{
    int row;
    int high;

    row = 0;
    high = 0;
    while (high != position)
    {
        while (mapinfo[high][row] != '\n' && mapinfo[high][row] != '\0')
        {
            if (mapinfo[high][row] == 'P')
            {
                fill_repeat(mapinfo, high, row);
                break;
            }
            row ++;
        }
        row = 0;
        high++;
    }
    return true;
}