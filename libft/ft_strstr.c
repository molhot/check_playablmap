/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:01:01 by user              #+#    #+#             */
/*   Updated: 2023/01/02 00:07:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../checker.h"

bool    ft_strstr(char *str1, char *str2)
{
    size_t position;

    position = 0;
    while (str1[position] != '\0')
    {
        if (str1[position] != str2[position])
            return (false);
        position++;
    }
    if (str1[position] == '\0' && str2[position] != '\0')
        return (false);
    return (true);
}