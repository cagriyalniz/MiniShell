/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:39:48 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/09 14:52:50 by eozmert          ###   ########.fr       */
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
		if (command.tokens->type_id == 13 || command.tokens->type_id == 7)
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

static int get_sub_type(t_command command)
{
	int fd_file;

	fd_file = 0;
	if (command.token_sub_type_id == 2)
		redir_in_exec(command);
	if (command.token_sub_type_id == 0)
		fd_file = redir_out_exec(command);
	if (command.token_sub_type_id == 1)
		fd_file = redir_here_out_exec(command);
	return (fd_file);
}

static int redir_child_proess(t_command command)
{
	int result;
	char *path;
	char **type;
	t_keyword *keyword;
	t_command *command_list1;
	
	result = 0;
	keyword = malloc(sizeof(t_keyword) * 8);
	command_list1 = malloc(sizeof(t_command) * 11);
	keyword_list(keyword);
	command_list(command_list1);
	path = command_find_path(command.keyword);
	type = create_type(command, path);
	dup2(command.file_fd, STDOUT_FILENO);
	close(command.file_fd);
	if (is_keyword_builtin(keyword, command.keyword))
		exit(0);
	else if (is_keyword_exec(keyword, command.keyword))
	{
		result = execve(path, type, g_env.env);
		if (result == -1)
			perror("error\n");
	}
	free(path);
	ft_free_dbl_str(type);
	return (0);
}

int redir_exec(t_command *command)
{
	printf("command_count %d\n", command->count);
	pid_t pid;

	if (command->count == 1)
		return (0);
	if (command->count > 1 && command->count != command->redir_count + 2)
		command->file_fd = get_sub_type(*command);
	if (command->count == command->redir_count + 2)
	{
		signal(SIGINT, proc_signal_handler);
		pid = fork();
		if (pid < 0)
			return (-1);
		if (pid == 0)
			redir_child_proess(*command);
		wait(&pid);
	}
	return (0);
}