/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:20:03 by dclark            #+#    #+#             */
/*   Updated: 2022/01/27 15:05:59 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_value(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = -1;
}

int	check_error_quotes(char *prompt, int *er)
{
	int	qt_1;
	int	qt_2;
	int	index;

	init_value(&qt_1, &qt_2, &index);
	while (prompt[++index])
	{
		if (prompt[index] == '\'' && qt_2 == 0)
		{
			if (qt_1 == 1)
				qt_1 = 0;
			else if (qt_1 == 0)
				qt_1 = 1;
		}
		else if (prompt[index] == '"' && qt_1 == 0)
		{
			if (qt_2 == 1)
				qt_2 = 0;
			else if (qt_2 == 0)
				qt_2 = 1;
		}
	}
	if ((qt_1 != 0) || (qt_2 != 0))
	{
		*er = 130;
		return (0);
	}
	*er = 0;
	return (1);
}
