/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:01:05 by roudouch          #+#    #+#             */
/*   Updated: 2021/11/14 14:01:07 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char const *s2);
unsigned int	ft_strlen(const char *str);
int				ft_index(const char *s, char c);
char			*ft_strdup(const char *s1);

#endif