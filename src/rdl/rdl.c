#include "../../include/header.h"

t_rdl *rdl_init(char *str)
{
	int i;
	t_rdl *rdl;
	char **split_str;

	i = 0;
	rdl = malloc(sizeof(t_rdl));
	rdl->command_list = malloc(sizeof(t_command) * 8);
	rdl->main_str = str;
	rdl->len = ft_strlen(rdl->main_str);
	split_str = ft_split(rdl->main_str, ' ');
	while (split_str[i])
		i++;
	rdl->word_count = i;
	return (rdl);
}

void rdl_clear(t_rdl *rdl)
{
	int i;

	i = 0;
	while (i < rdl->word_count)
	{
		// free(rdl->word[i].str);
		i++;
	}
	free(rdl->command_list);
	free(rdl->main_str);
}
