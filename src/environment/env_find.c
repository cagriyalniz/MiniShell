#include "../../include/header.h"

char	*env_find_value(char *key)
{
	int		i;
	int		key_len;
	int		env_id;

	i = -1;
	key_len = ft_strlen(key);
	env_id = env_find_id(key);
	if (env_id == -1)
		return (0);
	return (g_env.env[env_id] + key_len + 1);
}

int	env_find_id(char *key)
{
	int		i;
	int		key_len;
	char	*key_find;

	i = -1;
	key_len = ft_strlen(key);
	while(g_env.env[++i])
	{
		key_find = ft_split(g_env.env[i], '=')[0];
		if (ft_strnstr(key_find, key, ft_strlen(key_find)) != NULL)
		{
			free(key_find);
			return (i);
		}
	}
	return (-1);
}