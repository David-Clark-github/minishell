/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:38:17 by dclark            #+#    #+#             */
/*   Updated: 2022/01/19 14:49:09 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst	*parsing(t_pars *pars)
{
	//t_lst	*list;
	//t_pars	pars;

	//EXPENSION: si variable d'environement, elle l'etend
	pars->exp = expension(pars->prompt, &pars->error_num);
	if (pars->exp == NULL)
		return (NULL);
	pars->tab_separ = ft_separ(pars->exp, &pars->tab_len);
	check_tab(pars->tab_separ);
	pars->list = tab_to_list(pars->tab_separ);
	/*
	if (pars->tab_separ != NULL)
		ft_free_tab(pars->tab_separ, pars->tab_len);
	*/
	return (pars->list);
}
