/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:28:08 by dclark            #+#    #+#             */
/*   Updated: 2022/03/08 12:48:33 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **ev)
{
	(void)av;
	t_mini	*mini;

	mini = get_mini();
	init_mini(get_mini());
	mini->cp_ev = ft_copy_env(ev, 0);
	if (ac != 1)
	{
		printf("Aucun argument nécessaire pour minishell.\n");
		return (EXIT_FAILURE);
	}
	take_signal();
	while (1)
	{
		mini->prompt = readline("Minishell~ ");
		if (mini->prompt == NULL)
		{
			free_mini(mini);
			exit(EXIT_SUCCESS);
		}
		if (ft_strlen(mini->prompt) != 0)
			add_history(mini->prompt);
		if (ft_strlen(mini->prompt) != 0)
		{
			check_error_quotes(mini->prompt, &mini->er_num);
			if (mini->er_num != 0)
				printf("er_num = %d error de quotes\n", mini->er_num);
			if (mini->er_num == 0)
				parsing(get_mini());
			if (mini->list == NULL && mini->er_num == 0)
				printf("error during parsing\n");
			if (check_syntax(mini) == EXIT_FAILURE)
				printf("syntax error\n");
			if (mini->er_num == 0 && extract_lst(mini->list))
				print_lst(&mini->list);
			if (mini->er_num == 0 && mini->list->log == 3)
				ft_pwd(1);
			if (mini->er_num == 0 && mini->list->log == 6)
				ft_env(mini->cp_ev, 1);
			if (mini->er_num != 0)
				printf("er_num = %d\n", mini->er_num);
			ft_clearlst(&mini->list);
			ft_freetab(mini->tab_separ);
			/*
			ft_freetab(mini.tab_separ);
			if (mini.list != NULL) {
				if (mini.list->log == 6)
					ft_env(mini.cp_ev, 1);
				else if (mini.list->log == 4)
					ft_export("TUTU", "tata", &mini.cp_ev);
				else if (mini.list->log == 5)
					ft_unset("TUTU", &mini.cp_ev);
				else if (mini.list->log == 3)
					ft_pwd(1);
				else if (mini.list->log == 2)
					ft_cd("../");
			}
			*/
		}
	}
}
