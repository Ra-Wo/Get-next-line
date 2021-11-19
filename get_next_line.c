/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:00:58 by roudouch          #+#    #+#             */
/*   Updated: 2021/11/14 14:01:00 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

static char	*get_line(char *r)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (*r == '\0')
		return (NULL);
	while (r[i] && r[i] != '\n')
		i++;
	if (r[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = r[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*get_backup(char *backup)
{
	char	*str;
	int		start;
	int		i;

	start = 0;
	while (backup[start] && backup[start] != '\n')
		start++;
	if (backup[start] == '\n')
		start++;
	if (backup[start] == '\0')
	{
		free(backup);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(backup) - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (backup[start])
		str[i++] = backup[start++];
	str[i] = '\0';
	free(backup);
	return (str);
}

static char	*read_line(char *backup, int fd)
{
	int byte;
	char *buff;

	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	byte = 1;
	while (byte > 0 && ft_indexOf(backup, '\n') == -1)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == 0)
			break ;
		if (byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte] = '\0';
		backup = ft_strjoin(backup, buff);
	}
	free(buff);
	return (backup);
}

char *get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	backup = read_line(backup, fd);
	if (!backup)
		return (NULL);

	line = get_line(backup);
	backup = get_backup(backup);

	return (line);
}

#include<fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{

	int fd = open("/Users/roudouch/Desktop/GetNextLine/files/alternate_line_nl_no_nl", O_RDWR);
	for (int i = 0; i < 13; i++){
		char *c = get_next_line(fd);
		puts("\n");
		printf("%d = %s \n__________________________________________________________________________\n", i, c);
	}

	close(fd);

	return 0;
}