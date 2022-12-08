/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:39:48 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/08 20:32:31 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int type_size(t_command command)
{
	int i;
	int size;
	int type_size;

	i = -1;
	type_size = 0;
	size = token_size(command.tokens);
	while (++i < size)
	{
		if (command.tokens->type_id == 12)
			type_size++;
		get_next_token(&command.tokens);
	}
	return (type_size);
}

static char **create_type(t_command command, char *path)
{
	int i;
	int j;
	char *arg;
	char **type;

	i = -1;
	j = 1;
	arg = ft_strdup("");
	type = (char **)malloc(sizeof(char *) * ((type_size(command) + 1) + 2));
	type[0] = ft_strdup(path);
	while (++i < command.token_size)
	{
		if (command.tokens->type_id == 12 || command.tokens->type_id == 13 || command.tokens->type_id == 7)
			arg = ft_strjoin(arg, command.tokens->context);
		if (command.tokens->type_id == 12 || command.token_size - 1 == command.tokens->id)
		{
			type[j++] = ft_strdup(arg);
			arg = ft_strdup("");
		}
		get_next_token(&command.tokens);
	}
	type[j] = NULL;
	return (type);
}

static int redir_dbl_out_exec(t_command command)
{
	int fd_file;
	char *file_name;

	printf("redir out create\n");
	fd_file = 0;
	if (command.count < command.redir_count + 1 && command.count > 1)
	{
		file_name = redir_file_name(command);
		printf("file name : %s\n", file_name);
		fd_file = redir_file_create(command, file_name);
		close(fd_file);
	}
	else if (command.count == command.redir_count + 1 && command.count > 1)
	{
		file_name = redir_file_name(command);
		printf("file name : %s\n", file_name);
		fd_file = redir_file_create(command, file_name);
	}
	return (fd_file);
}


static int redir_out_exec(t_command command)
{
	int fd_file;
	char *file_name;

	printf("redir out create\n");
	fd_file = 0;
	if (command.count < command.redir_count + 1 && command.count > 1)
	{
		file_name = redir_file_name(command);
		printf("file name : %s\n", file_name);
		fd_file = redir_file_create(command, file_name);
		close(fd_file);
	}
	else if (command.count == command.redir_count + 1 && command.count > 1)
	{
		file_name = redir_file_name(command);
		printf("file name : %s\n", file_name);
		fd_file = redir_file_create(command, file_name);
	}
	return (fd_file);
}

static void redir_in_exec(t_command command)
{
	printf("redir in create\n");
	printf("file_name %s\n", redir_file_name(command));
}

static int get_sub_type(t_command command)
{
	int fd_file;

	fd_file = 0;
	if (command.token_sub_type_id == 2)
		redir_in_exec(command);
	if (command.token_sub_type_id == 0)
		fd_file = redir_out_exec(command);
	if (command.token_sub_type_id == 1)
		fd_file = redir_dbl_out_exec(command);
	return (fd_file);
}

int redir_exec(t_command command)
{
	printf("command_count %d\n", command.count);
	pid_t pid;
	int result;
	char *path;
	char **type;
	t_rdl	*rdl;
	static int file_fd;

	result = 0;
	rdl = malloc(sizeof(t_rdl) * 1);
	path = command_find_path(command.keyword);
	if (command.count == 1)
		return (0);
	if (command.count > 1 && command.count != command.redir_count + 2)
		file_fd = get_sub_type(command);
	if (command.count == command.redir_count + 2)
	{
		type = create_type(command, path);
		signal(SIGINT, proc_signal_handler);
		pid = fork();
		if (pid < 0)
			return (-1);
		if (pid == 0)
		{
			dup2(file_fd, STDOUT_FILENO);
			close(file_fd);
			result = execve(path, type, g_env.env);
			if (result == -1)
				perror("error\n");
		}
		wait(&pid);
	}
	free(path);
	return (0);
}