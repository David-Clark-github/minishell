/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:38:17 by dclark            #+#    #+#             */
/*   Updated: 2022/03/07 16:29:19 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*parsing(char *prompt, int *error_num)
{
	t_lst	*list;

	char	*exp;
	char	**separ;
	exp = expension(prompt, error_num);
	printf("exp = %s\n", exp);
	if (exp == NULL)
		return (NULL);
	separ = ft_separ(exp, &parsing.tk_len);
	/*
	printf("\ntab:\n");
	for (int i = 0; separ[i] != 0; i++)
		printf("%s\n", separ[i]);
	printf("\n");
	*/
	list = tab_to_list(separ);
	print_lst(&list);
	if (separ != NULL) {
		free(separ);
		separ = NULL;
	}
	return (exp);
}
