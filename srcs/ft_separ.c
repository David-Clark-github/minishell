/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separ.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:00:55 by david             #+#    #+#             */
/*   Updated: 2021/12/22 18:21:12 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	num_of_element(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == '\'')
		{
			res++;
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			i++;
		}
		else if (str[i] == '\"')
		{
			res++;
			i++;
			while (str[i] && str[i] != '\"')
				i++;
			i++;
		}
		else if (isalpha(str[i]))
		{
			res++;
			i++;
			while (str[i] && isalpha(str[i]))
				i++;
		}
	}
	return (res);
}

static char	*ft_strljoin(char *s1, char *s2, int len_s2)
{
	char	*dest;
	int		i_s;
	int		i_d;

	i_s = 0;
	i_d = 0;
	if (s1 == NULL && len_s2 == 0)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + len_s2 + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[i_s])
	{
		dest[i_d] = s1[i_s];
		i_s++;
		i_d++;
	}
	i_s = 0;
	while (s2[i_s] && len_s2--)
	{
		dest[i_d] = s2[i_s];
		i_d++;
		i_s++;
	}
	dest[i_d] = '\0';
	return (dest);
}

char	**ft_separ(char *str)
{
	char	**dest;
	int		i_dest;
	int		i_str;
	int		num_ele;
	
	num_ele = num_of_element(str);
	i_dest = 0;
	i_str = 0;
	printf("number of element = %d\n", num_ele);
	dest = (char **)malloc(sizeof(char *) * (num_ele + 1));
	for (int i = 0; i < num_ele; i++)
		dest[i] = NULL;
	while (str[i_str] == ' ')
		i_str++;
	while (str[i_str])
	{
		if (str[i_str] == ' ')
			i_str++;
		if (str[i_str] == '\'')
		{
			i_str++;
			while (str[i_str] && str[i_str] != '\'')
			{
				dest[i_dest] = ft_strljoin(dest[i_dest], &str[i_str], 1);
				i_str++;
			}
			i_dest++;
			if (str[i_str] == '\'')
				i_str++;
		}
		else if (str[i_str] == '\"')
		{
			i_str++;
			while (str[i_str] && str[i_str] != '\"')
			{
				dest[i_dest] = ft_strljoin(dest[i_dest], &str[i_str], 1);
				i_str++;
			}
			i_dest++;
			if (str[i_str] == '\"')
				i_str++;
		}
		else if (isalpha(str[i_str]) != 0)
		{
			while (str[i_str] && str[i_str] != ' ' && str[i_str] != '\'' && str[i_str] != '\"')
			{
				dest[i_dest] = ft_strljoin(dest[i_dest], &str[i_str], 1);
				i_str++;
			}
			i_dest++;
		}
		//printf("i_dest = %d\n", i_dest);
		//printf("str = %s\n", &str[i_str]);
	}
	dest[i_dest] = 0;
	return (dest);
}