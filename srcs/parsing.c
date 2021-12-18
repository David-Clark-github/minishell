/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:38:17 by dclark            #+#    #+#             */
/*   Updated: 2021/12/18 18:32:38 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*parsing(char *prompt)
{
	int	i;
	t_lst	*list;

	list = NULL;
	i = 0;
	while (prompt[i] == ' ')
		i++;
	add_lst_back(&list, "toto", 5);
	add_lst_back(&list, "tutu", 4);
	add_lst_back(&list, "tata", 2);
	print_lst(&list);
	return (prompt);
}
