/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 21:23:41 by user              #+#    #+#             */
/*   Updated: 2023/01/01 22:44:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main()
{
    char    **mapinfo;
    char    *line;

    //map読み込み
    line = get_next_line("src/map1.ber");
    while (line != NULL)
    {
        printf("%s\n", line);
        line = get_next_line("src/map1.ber");
    }
}