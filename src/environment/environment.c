#include "../../include/header.h"

int env_init(char **env)
{
	int		i;
	int		count;

	i = -1;
	count = env_len(env);
	g_env = (char **)malloc(sizeof(char *) * (count ) + 1);
	if (g_env == NULL)
		return (307);
	while (env[++i])
		g_env[i] = ft_strdup(env[i]);
	return (0);
}
