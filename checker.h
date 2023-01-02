/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 21:23:56 by user              #+#    #+#             */
/*   Updated: 2023/01/02 17:13:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdbool.h>

char	*get_next_line(int fd_num);
char	*ft_strchr(const char (*s), int c);
size_t	ft_strlen(const char (*string_row));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char (*s), int c);
size_t	ft_strlen(const char (*string_row));
char	*ft_strjoin(char const *s1, char const *s2);
bool    map_basiccheck(char **mapinfo);
bool    fill_check(char **mapinfo, int position);

#endif