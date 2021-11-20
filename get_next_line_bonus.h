/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:18:43 by roudouch          #+#    #+#             */
/*   Updated: 2021/11/20 10:18:47 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char const *s2);
unsigned int	ft_strlen(const char *str);
int				ft_index(const char *s, char c);
char			*ft_strdup(const char *s1);

#endif
