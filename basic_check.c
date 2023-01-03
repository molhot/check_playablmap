/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 21:23:31 by user              #+#    #+#             */
/*   Updated: 2023/01/03 14:56:18 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//端の壁のチェックを行う
//EやP、Cがないか確認する

#include "checker.h"

static void char_increment(char **map, size_t high, size_t row, size_t *P, size_t *E, size_t *C)
{
    while (map[high] != NULL)
    {
        while (map[high][row] != '\0')
        {
            if (map[high][row] == 'P')
                *P = *P + 1;
            else if (map[high][row] == 'E')
                *E = *E + 1;
            else if (map[high][row] == 'C')
                *C = *C + 1;
            row++;
        }
        row = 0;
        high++;
    }
}

bool mandatory_mapcheck(char **map)
{
    size_t  p;
    size_t  e;
    size_t  c;
    int      map_highposition;
    size_t  rowposition;

    p = 0;
    e = 0;
    c = 0;
    map_highposition = 0;
    rowposition = 0; 
    char_increment(map, map_highposition, rowposition, &p, &e, &c);
    if (p == 1 && e > 0 && c > 0)
        return (true);
    return (false);
}

static size_t	ft_strlen_withn(const char (*string_row))
{
	size_t	stringlen;

	stringlen = 0;
	while (string_row[stringlen] != '\0' && string_row[stringlen] != '\n')
		stringlen++;
	return (stringlen);
}

bool map_rowcheck(char **mapinfo)
{
    size_t position;
    size_t befor_row;
    size_t row;

    position = 0;
    befor_row = ft_strlen_withn(mapinfo[position]);
    while (mapinfo[position + 1] != NULL)
    {
        position++;
        row = ft_strlen_withn(mapinfo[position]);
        if (row != befor_row)
            return (false);
        befor_row = row;
    }
    return (true);
}

bool    map_basiccheck(char **mapinfo)
{
    size_t  map_position;
    size_t  position;
    size_t  map_high;
    size_t  map_row;
    //intを用意して数を更新していく、数が0の場合エラー処理

    map_position = 0;
    position = 0;
    while (mapinfo[map_position] != NULL)
        map_position++;
    map_high = map_position;
    if (map_rowcheck(mapinfo) != true)
        return (false);
    if (mandatory_mapcheck(mapinfo) != true)
        return (false);
    map_row = ft_strlen(mapinfo[0]);
    map_position = 0;
    while (mapinfo[map_position] != NULL)
    {
        printf("%s", mapinfo[map_position]);
        if (map_position == 0 || map_position == map_high)
        {
            while (mapinfo[map_position][position] != '\n')
            {
                if (mapinfo[map_position][position] != '1')
                    return (false);
                position++;
            }
        }
        else
        {
            while (mapinfo[map_position][position] != '\0')
            {
                if ((position == 0 || position == map_row) && mapinfo[map_position][position] != '1')
                    return (false);
                position++;
            }
        }
        map_position++;
        position = 0;
    }
    return (true);
}