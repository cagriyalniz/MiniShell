/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:08:38 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/16 16:56:36 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

typedef struct s_token
{
	int				id;
	int				len;
	char			*type;
	char			*context;
	struct s_token	*next;
}	t_token;

typedef struct s_command
{
	char				*type;
	char				*arg;
}	t_command;

typedef struct s_rdl
{
	int				len;
	int				word_count;
	char			*main_str;
	t_command		*command_list;
	t_command		command;
	t_token			*token;
	struct s_syntax	*syntax_list;
}	t_rdl;

typedef struct s_syntax
{
	char	*name;
	char	*sybl;
	int		count;
	int		(*f)(t_rdl *);
}	t_syntax;

typedef struct s_syntax_tree
{
	char	*context;
	struct	s_syntax_tree	*left;
	struct	s_syntax_tree	*right;
}	t_syntax_tree;



//main
void			routine();
//lexcical
t_token			*token_add(t_token *token, char **ptr);
void			token_append(t_token **token, t_token *new);
t_token			*token_last(t_token *token);
t_token			*token_new(char *context);
int				print_token(t_token *token);
void			token_delone(t_token *token);
void			token_clear(t_token **token);
int				token_size(t_token *token);
void			token_add_index(t_token **token);
t_token			*get_token_id(t_token *token, int id);
void			get_next_token(t_token **token);
//rd_line
char			*ft_read_line(void);
t_rdl			*rdl_init(t_rdl *rdl);
void			rdl_clear(t_rdl *rdl);
//core
int				check_white_space(char *input);
int				count_char(char *str, char c);
//history
int				my_add_history(char *str);
//parser
void			parser(t_rdl *rdl);
t_rdl			*parser_analizer(t_rdl *rdl);
//commands
void			command_list(t_command *commands);
int				commands_clear(t_command *commands);
int				commands_size(t_command *commands);
//syntax
void			syntax(t_rdl *rdl);
int				syntax_analizer(t_rdl *rdl);
void			syntax_list(t_syntax *syntax);
//quoet
int				single_quote(t_rdl *rdl);
//lexical
void			lexical_analizer(t_rdl *rdl);
#endif
