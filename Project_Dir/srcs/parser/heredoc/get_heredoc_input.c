/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyi <tyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:16:11 by minseok2          #+#    #+#             */
/*   Updated: 2023/01/11 21:00:36 by tyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <readline/readline.h>
#include "../../../includes/data.h"
#include "../../../includes/parser.h"
#include "../../../includes/executor.h"
#include "../../../includes/signal_handler.h"

int	get_heredoc_input(char *filename, char *limiter)
{
	int		fd;
	int		wstatus;
	pid_t	pid;
	char	*input_line;

	fd = open(filename, O_WRONLY);
	pid = fork();
	reset_signal_before_fork(pid);
	if (pid == 0)
	{
		while (1)
		{
			input_line = readline("> ");
			if (ft_strcmp(input_line, limiter) == 0)
			{
				free(input_line);
				break ;
			}
			(ft_putendl_fd(input_line, fd), free(input_line));
		}
		exit(EXIT_SUCCESS);
	}
	(waitpid(pid, &wstatus, 0), close(fd));
	return (wexitstatus(wstatus));
}
