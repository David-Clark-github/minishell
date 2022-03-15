/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:28:08 by dclark            #+#    #+#             */
/*   Updated: 2022/03/15 13:02:24 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **ev)
{
	(void)av;
	t_mini	*mini;

	mini = get_mini();
	init_mini(mini);
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
			ft_exit(mini->er_num);
		if (ft_strlen(mini->prompt) != 0)
		{
			add_history(mini->prompt);
			mini->er_num = check_error_quotes(mini->prompt, &mini->er_num);
		}
		if (ft_strlen(mini->prompt) != 0 && mini->er_num != 0)
		{
			if (mini->er_num != 0)
				printf("er_num = %d error de quotes\n", mini->er_num);
			if (mini->er_num != -1)
				parsing(mini);
			if (mini->list == NULL && mini->er_num == 0)
				printf("error during parsing\n");
			if (check_syntax(mini) == EXIT_FAILURE)
				printf("syntax error\n");
			if (mini->er_num != -1 && extract_lst(mini->list))
			 	print_lst(&mini->list);
			//if (mini->list && mini->list->log == 4)
			//	ft_export("TUTU", "tata", &mini->cp_ev);
			if (mini->list && mini->er_num != -1 && mini->list->log == 6)
				ft_env(mini->cp_ev, 1);
			if (mini->er_num == 0 && mini->list && mini->list->log == 3)
			 	ft_pwd(1);
			if (mini->er_num == 0 && mini->list && mini->list->log == 2)
				ft_cd(mini->tab_separ[1]);
			if (mini->list && mini->list->log == 4)
				ft_export("toto", "tutu", &mini->cp_ev);
			if (mini->list && mini->list->log == 5)
				ft_unset("toto", &mini->cp_ev);
			// if (mini->er_num == 0 && mini->list->log == 6)
			// 	ft_env(mini->cp_ev, 1);
			// if (mini->er_num == 0 && mini->list->log == 4)
			// 	arg_export(mini->tab_separ, mini);
			// if (mini->er_num != 0)
			// 	printf("er_num = %d\n", mini->er_num);
			// ft_freetab(mini->tab_separ);
		//	exec_instructions(mini);
		}
		ft_free_mini(mini, 1);
	}
}
