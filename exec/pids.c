/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pids.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seciurte <seciurte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:38:33 by seciurte          #+#    #+#             */
/*   Updated: 2022/03/09 14:22:11 by seciurte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pids	*create_pid(void)
{
	t_pids		*pid;

	pid = malloc(sizeof(t_pids));
	if (pid == NULL)
		exit_error(__LINE__);
	pid->pid = 0;
	pid->next = NULL;
	return (pid);
}

void	add_pid_to_pids(t_mini *mini, t_pids *pid)
{
	t_pids		*tmp;

	if (mini->pids == NULL)
		mini->pids = pid;
	else
	{
		tmp = mini->pids;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = pid;
	}
}

void	wait_for_forks(t_mini *mini)
{
	t_pids		*pid;

	pid = mini->pids;
	while (pid)
	{
		waitpid(pid->pid, NULL, 0);
		pid = pid->next;
	}
}

void	free_pids(t_pids **pids)
{
	t_pids		*tmp;

	tmp = *pids;
	while (*pids)
	{
		(*pids) = (*pids)->next;
		free(tmp);
		tmp = (*pids);
	}
}