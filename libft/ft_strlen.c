/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:45:35 by user              #+#    #+#             */
/*   Updated: 2023/01/01 23:12:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../checker.h"

size_t	ft_strlen(const char (*string_row))
{
	size_t	stringlen;

	stringlen = 0;
	while (string_row[stringlen] != '\0')
		stringlen++;
	return (stringlen);
}