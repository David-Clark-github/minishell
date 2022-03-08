/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:59:08 by dclark            #+#    #+#             */
/*   Updated: 2022/03/08 12:43:56 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//[readline] [rl_clear_history] [rl_on_new_line] [rl_replace_line]
//[rl_redisplay] [add_history]
# include <readline/readline.h>
# include <readline/history.h>

//[strerror]
# include <string.h>

//[printf] [perror]
# include <stdio.h>

//[malloc] [free] [getenv]
# include <stdlib.h>

//[ioctl] 
# include <sys/ioctl.h>

//[write] [access] [read] [close] [exit] [getcwd] [chdir] [unlink] [execve]
//[dup] [dup2] [pipe] [isatty] [ttyname] [ttyslot] [tcgetattr]
# include <unistd.h>
# include <termios.h>

//[open] [fork] [waitpid] [wait3/4] [siganl] [stat] [lstat] [fstat]
//[kill] [opendir] [readdir] [closedir]
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/wait.h>

//[tgetent] [tgetflag] [tgetnum] [tgetstr] [tgoto] [tputs]
# include <curses.h>
# include <term.h>

typedef struct	s_lst {
	struct s_lst	*next;
	char			*str;
	int				log;
	int				iter;
}				t_lst;

typedef struct	s_parsing {
	char	*prompt;
	char	*exp;
	char	**tab_separ;
	int		tab_len;
	t_lst	*list;
	int		error_num;
}				t_pars;

typedef struct	s_minishell {
	char	**cp_ev;
	int		er_num;
	char	*prompt;
	char	*exp;
	char	**tab_separ;
	int		tab_len;
	t_lst	*list;
}				t_mini;

//PARSING
void	parsing(t_mini *mini);
char	*expension(char *prompt, int *error_num, char **cp_ev);
char	*quotes_exp(char *str);
int		check_error_quotes(char *prompt, int *er);
void	add_lst_back(t_lst **head, char *str, int log, int iter);
void	print_lst(t_lst **head);
char	**ft_separ(char *str, int *tk_len);
int		extract_lst(t_lst *list);
int		check_tab(char **tab_separ);
int		check_cmd(char **tab_separ);
int		check_syntax(t_mini *mini);
int		diff_cmd_redir(char *str);
int		diff_cmd(char *str);
int		diff_redir(char *str);

//BUILTINS
int		ft_echo(char *str, int arg, int fd);
int		ft_pwd(int fd);
int		ft_env(char **tab_env, int fd);
int		ft_export(char *name, char *data, char ***tab_env);
int		ft_unset(char *name, char ***tab_env);
int		ft_cd(char *path);

//UTILS
int		ft_strlen(char *str);
int		ft_tablen(char **tableau);
int		ft_isalpha(int c);
char	*ft_strdup(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char *str_1, char *str_2);
char	*ft_strljoin(char *s1, char *s2, int s2_len);
char	**ft_copy_env(char **tab_env, size_t add);
void	ft_freetab(char **tabx);
void	init_mini(t_mini *mini);
void	free_mini(t_mini *mini);
int		ft_checkredir(char c);
int		ft_checkquote(char c);
int		ft_checkcara(char c, char *str);
void	ft_clearlst(t_lst **lst);
t_mini	*get_mini(void);

//DO NOT USE THE NAME "tab" FOR PARAMETER NAME
//term.h USES IT

t_lst	*tab_to_list(char **tabx, int tk_len);

//TEST
void	take_signal(void);
#endif
