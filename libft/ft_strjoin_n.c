/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:17:59 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/02/29 14:18:11 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_n(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		size;

	size = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	string = malloc(sizeof(char) * (size + 1));
	if (!string)
		return (NULL);
	size = -1;
	while (s1[++size])
		string[size] = s1[size];
	i = 0;
	while (s2[i] && s2[i] != '\n')
		string[size++] = s2[i++];
	if (s2[i] == '\n')
	{
		string[size] = '\n';
		size++;
	}
	string[size] = '\0';
	free(s1);
	return (string);
}