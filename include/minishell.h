/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbied <oelbied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:22:56 by sidrissi          #+#    #+#             */
/*   Updated: 2025/04/20 20:29:17 by oelbied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h> 
#include <limits.h>

#define ERROR "minishell: syntax error near unexpected token\n"
#define name_length 9

//for the env 
typedef struct t_listenv
{
	char *constvrble;
	char *pat;
	struct t_listenv *next;
}t_listenv;

typedef enum s_keyword
{
	READ_IN,
	WRITE_OUT,
	APPEND,
	HERDOC,
	PIPE,
	PIPES,
	WORD,
	START,
	FREAD_IN,
	FWRITE_OUT,
	F_HERDOC,
	F_APPEND,
	CMD,
} t_keyword;

typedef struct s_quote_data
{
	char *line;
	int *i;
	char **buffer;
	// int *buffer_index;
} t_quote_data;


typedef	struct s_initalize
{
	int		j;
	char	quote;
    char	*new_buffer;
	char	*res;
}	t_initalize;


typedef struct s_token
{
	char 			**value;
	int				fd;
	t_keyword 		type;
	struct s_token 	*next;
} t_token;

typedef struct s_expand
{
	char *res;
	int i;
	int dollar_count;
	int var_len;
	char *var_name;
} t_expand;
/*              ******************************************************************************************        */

typedef struct s_redir
{
	char			*name;
	int				fd;
	t_keyword		type;
	struct s_redir 	*next;
} t_redir;

typedef struct s_data
{
	char *cmd;
	char **args;
	t_redir *file;
	struct s_data *next;
} t_data;

// that list for echo
typedef struct t_list
{
	char *data;
	struct t_list *next;
}t_list;
// free in file garbage.c
typedef struct	s_var_data
{
	t_data *current;
	t_data *next;
	t_redir *redir;
	t_redir *next_redir;
	int		i;
}	t_var_data;


// Function prototypes
t_data *parsing(t_token **tokens);
// char *ft_strjoin_free(char *s1, char *s2);

/*********************Parsing**********************/

/*main.c*/
int check_quotes(char *line, int i, int count_quote);
t_token *lexing(char *line);
// void lexing(char *line);

/*---------------tokenization---------------*/
int sp(char c);
// void handle_quotes(t_quote_data *data);
// void handle_special_chars(char *line, int *i, t_token **head);
// void handle_words(char *line, int *i, char *buffer, int *buffer_index);
// void handle_words(char *line, int *i, char **buffer);
t_token *tokenization(char *line, int i);

/*---------------garbage---------------*/
// Linked list:
void free_tokens(t_token *tokens);
t_token *deldum(t_token **head);
void free_data(t_data *data);

/*---------------error---------------*/
int error(t_token *tokens);

/*---------------expand---------------*/
void ft_expand(t_token *tokens);

/*---------------ft_rename------------*/
void ft_rename(t_token *tokens);

/*-------------ft_herdoc--------------*/

void ft_herdoc(t_token **tokens);

/*===============libft===============*/
char *ft_substr(char *s, int start, int len);
void ft_putstr_fd(char *s, int fd);
int ft_strlen(char *s);
char *ft_strdup(char *s);
int ft_isprint(int c);
int ft_cmp(char *word);
char *ft_strjoin(char *s1, char *s2);
// Linked list:
t_token *ft_lstlast(t_token *lst);
t_token *ft_lstnew(char *content, t_keyword type);
void ft_lstadd_back(t_token **lst, t_token *new);

int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isdigit(int c);
void *ft_memset(void *b, int c, size_t len);
int ft_strcmp(char *s1, char *s2);

/***************ft_split************* */

void *ft_free(char **strs, int count);
char **ft_split(char *s, char c);


// FOR Exequshen 
void	ft_lstadd_back_ex(t_listenv **lst, t_listenv *new);
t_listenv *ft_lstnew_env(char *content, char *path);
void	ft_lstdelone(t_listenv *lst, void (*del)(void*));
void ft_env(char **env, t_listenv **head);
void ft_tchc_data(t_data *data,t_listenv *head);
void ft_pwd(t_listenv *head);
void ft_echo(t_data *data);
void ft_unset(t_data *data,t_listenv **head);
int  ft_exit(t_data *data);
int ft_cd(t_data *data);
void ft_export(t_listenv **head, t_data *data);
int  thcking_pluss(char *str);
int tchking_egal(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_tchk_cotachen( char *s1);


/* just remove them cause we don't use them*/
// int		ft_strncmp(char *s1, char *s2, int n);/*not use it check before remove it */
// char	*ft_strndup(char *s, size_t n);/*not use it check before remove it */
// char	*ft_allocate(char **res, int len);/*not use it check before remove it */
// char	*ft_strcat(char *dest, char *src);/*not use it check before remove it */
// char	*ft_strncpy(char *dest, char *src, int n);/*not use it check before remove it */

#endif