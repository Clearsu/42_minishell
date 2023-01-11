/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_file_using_mktemp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:04:25 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/11 11:39:50 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/signal_handler.h"

static void	execve_cmd(t_data *data, int pip[2], char *cmdpath, char **cmdargv)
{
	char	**envp;

	envp = envp2arr(&data->envp_list);
	close(pip[READ_END]);
	dup2(pip[WRITE_END], STDOUT_FILENO);
	close(pip[WRITE_END]);
	execve(cmdpath, cmdargv, envp);
}

static char	*read_filename_from_pipe(pid_t pid, int pip[2])
{
	char	*filename;
	int		last_index;
	int		wstatus;

	waitpid(pid, &wstatus, 0);
	if (wexitstatus(wstatus) != 0)
		return (NULL);
	filename = get_next_line(pip[READ_END]);
	last_index = ft_strlen(filename) - 1;
	if (filename[last_index] == '\n')
		filename[last_index] = '\0';
	return (filename);
}

char	*make_file_using_mktemp(t_data *data, \
										char *mktemp_path, char **mktemp_argv)
{
	char	*filename;
	int		pip[2];
	int		ret;
	pid_t	pid;

	if (mktemp_path == NULL)
		return (NULL);
	ret = pipe(pip);
	pid = fork();
	if (pid == 0)
		execve_cmd(data, pip, mktemp_path, mktemp_argv);
	close(pip[WRITE_END]);
	filename = read_filename_from_pipe(pid, pip);
	return (filename);
}
