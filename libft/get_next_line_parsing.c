/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:29:25 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/04 14:17:40 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

void	ft_new_buffer(char *str)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!ft_strnchr(str))
	{
		str[0] = '\0';
		return ;
	}
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i])
		i++;
	j = 0;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = '\0';
}

char	*get_next_line_n(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	ssize_t		bytes_read;

	bytes_read = 1;
	str = ft_strdup("\0");
	if (!str)
		return (NULL);
	while (bytes_read && !(ft_strnchr(str)))
	{
		if (!buffer[0])
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read == -1)
				return (free(str), NULL);
			buffer[bytes_read] = '\0';
		}
		str = ft_strjoin_n(str, buffer);
		if (!str)
			return (NULL);
		ft_new_buffer(buffer);
	}
	if (!bytes_read && !str[0])
		return (free(str), NULL);
	return (str);
}

// int main()
// {
//     int fd;
//     fd = open("file1.txt", 2);
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd));
//     // static char *buffer = "coucou\nboy you give good\nlove I won t lie\nyeah";
//     // ft_new_buffer(buffer);
//     // printf("%s\n", buffer);
// }

// int main() 
// {
// 	int fd = open("file1.txt", 2);
// 	//printf("%s", get_next_line(fd));
// 	//printf("%s", get_next_line(fd));
// 	//printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));

// 	char	*s;

// 	while ((s = get_next_line(fd)))
// 	{
// 	 	printf("%s\n", s);
// 	 	free(s);
// 	}
// 	// printf("%s", s);
// 	// free(s);
// 	return (0);
// }
