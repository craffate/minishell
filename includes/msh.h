/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:37:41 by craffate          #+#    #+#             */
/*   Updated: 2017/03/08 13:57:40 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_H
# define MSH_H
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define MSH_BUFSIZE		256
# define MSH_MERROR			"Memory allocation error\n"
# define MSH_IERROR			"Input couldn't be read\n"
# define MSH_FORKFAIL		"Failed to fork\n"
# define MSH_UNKNOWNCMD		"Unknown command\n"
# define MSH_BINNOTFOUND	"Binary couldn't be found\n"
# define MSH_DENIED			"Access denied\n"
# define MSH_INVALID		"Invalid input\n"
# define MSH_NOENV			"Environement variable doesn't exist\n"
# define MSH_NOPATH			"Path couldn't be found\n"

char			*read_input(void);
int				exec(char **argv, char ***envp);
char			**split_input(const char *buf);
char			**split_path(const char **envp);
char			*join_path(const char *s1, const char *s2);
char			*clean_path(const char *path);
int				isbuiltin(const char *s);
void			exec_builtin(const char **argv, char ***envp);
void			builtin_cd(const char **argv, char **envp);
void			builtin_cd_nopath(char **envp);
void			builtin_cd_prev(char **envp);
void			builtin_cd_chdir(char **ptr);
void			builtin_echo(const char **argv);
void			builtin_env(const char **envp);
void			builtin_setenv(const char **argv, char ***envp);
void			builtin_unsetenv(const char **argv, char ***envp);
int				find_env(const char **envp, const char *env);
void			free_env(char **envp);
void			envp_add(const char *var, char ***envp);
char			*pwd_print(const char **envp);
void			error_handler(int error);
int				path_check(const char *pwd, const char *f);
int				abs_path(const char *path);
unsigned int	path_scan(const char *path);
void			status_handler(int status);

#endif
