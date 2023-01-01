/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 21:23:31 by user              #+#    #+#             */
/*   Updated: 2023/01/02 00:39:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//端の壁のチェックを行う
//EやP、Cがないか確認する

#include "checker.h"

bool map_rowcheck(char **mapinfo)
{
    size_t position;
    size_t befor_row;
    size_t row;

    position = 0;
    befor_row = ft_strlen(mapinfo[position]);
    while (mapinfo[position] != NULL)
    {
        position++;
        row = ft_strlen(mapinfo[position]);
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
                {
                    printf("this map is not playable\n");
                    return (false);
                }
                //mapで使われている文字を確認する
                //ここ
                position++;
            }
        }
        else
        {
            while (mapinfo[map_position][position] != '\0')
            {
                if ((position == 0 || position == map_row) && mapinfo[map_position][position] != '1')
                    return (false);
                //mapで使われている文字を確認する
                //ここ
                position++;
            }
        }
        map_position++;
        position = 0;
    }
    return (true);
}