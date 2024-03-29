/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:54:54 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/12 15:55:46 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

char	*env_find_value(char *key)
{
	int		i;
	int		key_len;
	int		env_id;
	char	*key_find;

	i = -1;
	key_len = 0;
	env_id = env_find_id(key);
	if (env_id == -1)
		return (0);
	while (g_env.env[++i])
	{
		key_find = ft_split(g_env.env[i], '=')[0];
		key_len = ft_strlen(key_find);
		if (ft_strncmp(key_find, key, ft_strlen(key_find)) == 0)
		{
			free(key_find);
			return (g_env.env[env_id] + key_len + 1);
		}
	}
	return (0);
}

int	env_find_id(char *key)
{
	int		i;
	int		key_len;
	char	*key_find;

	i = -1;
	key_len = ft_strlen(key);
	while (g_env.env[++i])
	{
		key_find = ft_split(g_env.env[i], '=')[0];
		if (ft_strncmp(key_find, key, ft_strlen(key_find)) == 0
			&& key_len == (int)ft_strlen(key_find))
		{
			free(key_find);
			return (i);
		}
	}
	return (-1);
}
