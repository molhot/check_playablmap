/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:50:22 by user              #+#    #+#             */
/*   Updated: 2023/01/03 15:22:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char    **fill_repeat(char **map_copy, int high, int row)
{
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
    return map_copy;
}

static bool playable_or_not(char **map)
{
    size_t  map_high;

    map_high = 0;
    while (map[map_high] != NULL)
    {
        if (ft_strchr(map[map_high], 'E') != NULL || ft_strchr(map[map_high], 'C') != NULL)
            return false;
        map_high++;
    }
    return true;
}

bool    fill_check(char **mapinfo, int position)
{
    int     row;
    int     high;
    bool    judge;

    row = 0;
    high = 0;
    while (high != position)
    {
        while (mapinfo[high][row] != '\n' && mapinfo[high][row] != '\0')
        {
            if (mapinfo[high][row] == 'P')
                mapinfo = fill_repeat(mapinfo, high, row);
            row ++;
        }
        row = 0;
        high++;
    }
    int i = 0;
    while (mapinfo[i] != NULL)
    {
        printf("%s\n", mapinfo[i]);
        i++;
    }
    judge = playable_or_not(mapinfo);
    return (judge);
}