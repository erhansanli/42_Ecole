/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esanli <esanli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:00:50 by esanli            #+#    #+#             */
/*   Updated: 2022/10/14 16:51:42 by esanli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char	*ft_free(char *record, char *buffer)
{
	char	*new;

	new = ft_strjoin(record, buffer);
	free(record);
	return (new);
}

char	*get_line(char *record)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!record[i])
		return (NULL);
	while (record[j] && record[j] != '\n')
		j++;
	if (record[j] == '\n')
		line = malloc(sizeof(char) * (j + 2));
	else
		line = malloc(sizeof(char) * (j + 1));
	if (!line)
		return (NULL);
	while (record[i] && record[i] != '\n')
	{
		line[i] = record[i];
		i++;
	}
	if (record[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*savelinelen(char *record)
{
	size_t	len;
	int		i;
	int		j;
	char	*str;

	len = ft_strlen(record);
	i = 0;
	j = 0;
	while (record[i] && record[i] != '\n')
		i++;
	if (!record[i])
	{
		free (record);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (len - i));
	if (!str)
		return (NULL);
	i++;
	while (record[i])
		str[j++] = record[i++];
	str[j] = '\0';
	free(record);
	return (str);
}

char	*readline(char *record, int fd)
{
	char		*buffer;
	int			read_count;

	read_count = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(record, '\n')) && read_count > 0)
	{	
		read_count = read(fd, buffer, BUFFER_SIZE);
		if ((read_count == 0 && !record) || read_count == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_count] = '\0';
		if (!record)
			record = ft_strdup(buffer);
		else
			record = ft_free(record, buffer);
	}
	free(buffer);
	return (record);
}

char	*get_next_line(int fd)
{
	static char		*record;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	record = readline(record, fd);
	if (!record)
		return (NULL);
	line = get_line(record);
	record = savelinelen(record);
	return (line);
}
