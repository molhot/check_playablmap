/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 21:23:41 by user              #+#    #+#             */
/*   Updated: 2023/01/03 16:19:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main()
{
    char    **mapinfo;
    char    *line;
    int     fd;
    int     position;

    //map読み込み
    char *textdata;

    textdata = "src/map2.ber";
    fd = open(textdata, O_RDONLY);
    line = get_next_line(fd);
    position = 1;
    while (line != NULL)
    {
        position++;
        free(line);
        line = get_next_line(fd);
    }
    mapinfo = (char **)malloc(sizeof(char *) * (position + 1));
    fd = open(textdata, O_RDONLY);
    line = get_next_line(fd);
    position = 0;
    while (line != NULL)
    {
        mapinfo[position] = ft_strdup(line);
        printf("%s", mapinfo[position]);
        free(line);
        position++;
        line = get_next_line(fd);
    }
    mapinfo[position] = NULL;
    printf("map is %d\n", map_basiccheck(mapinfo));
    printf("map is not playable or not : %d\n", fill_check(mapinfo, position));
    free_arrangement(mapinfo);
    system("leaks a.out");
}