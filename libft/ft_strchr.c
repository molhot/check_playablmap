/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:45:29 by user              #+#    #+#             */
/*   Updated: 2023/01/01 23:10:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../checker.h"

char	*ft_strchr(const char (*s), int c)
{
	size_t	num;

	if (s == NULL)
		return (NULL);
	num = 0;
	while (s[num] != '\0')
	{
		if ((unsigned char)s[num] == (unsigned char)c)
			return ((char *)s + num);
		num = num + 1;
	}
	return (NULL);
}