/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:45:32 by user              #+#    #+#             */
/*   Updated: 2023/01/01 23:11:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../checker.h"

static	char	*input_char(const char *insert, char *inserted)
{
	while ((*insert) != '\0')
	{
		*inserted = *insert;
		insert = insert + 1;
		inserted = inserted + 1;
	}
	return (inserted);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*src_sub;

	len = ft_strlen(s);
	src_sub = (char *)malloc(sizeof(char) * (len + 1));
	if (src_sub == NULL)
		return (NULL);
	while ((*s) != '\0')
	{
		*src_sub = *s;
		s = s + 1;
		src_sub = src_sub + 1;
	}
	*src_sub = '\0';
	src_sub = src_sub - len;
	return (src_sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	char		*dust;
	char		*dust_first;

	if ((s1 == NULL) && (s2 == NULL))
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	dust = (char *)malloc(sizeof(char) * (len + 1));
	if (!(dust))
		return (NULL);
	dust_first = dust;
	dust = input_char(s1, dust);
	dust = input_char(s2, dust);
	*dust = '\0';
	free((char *)s1);
	return (dust_first);
}