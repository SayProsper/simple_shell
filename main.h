#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
    char **av;
    char *input;
    char **args;
    int status;
    int counter;
    char **_environ;
    char *pid;
} data_shell;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
    char separator;
    struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
    char *line;
    struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
    int len_var;
    char *val;
    int len_val;
    struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
    char *name;
    int (*f)(data_shell *datash);
} builtin_t;

/* sya_lists.c */
sep_list *add_sya_sep_node_end(sep_list **head, char sep);
void free_sya_sep_list(sep_list **head);
line_list *add_sya_line_node_end(line_list **head, char *line);
void free_sya_line_list(line_list **head);

/* sya_lists2.c */
r_var *add_sya_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_sya_rvar_list(r_var **head);

/* sya_str functions */
char *_sya_strcat(char *dest, const char *src);
char *_sya_strcpy(char *dest, char *src);
int _sya_strcmp(char *s1, char *s2);
char *_sya_strchr(char *s, char c);
int _sya_strspn(char *s, char *accept);

/* sya_mem.c */
void _sya_memcpy(void *newptr, const void *ptr, unsigned int size);
void *_sya_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_sya_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* sya_str2.c */
char *_sya_strdup(const char *s);
int _sya_strlen(const char *s);
int sya_cmp_chars(char str[], const char *delim);
char *_sya_strtok(char str[], const char *delim);
int sya_isdigit(const char *s);

/* sya_str3.c */
void sya_rev_string(char *s);

/* check_syntax_error.c */
int sya_repeated_char(char *input, int i);
int sya_error_sep_op(char *input, int i, char last);
int sya_first_char(char *input, int *i);
void sya_print_syntax_error(data_shell *datash, char *input, int i, int bool);
int sya_check_syntax_error(data_shell *datash, char *input);

/* shell_loop.c */
char *sya_without_comment(char *in);
void sya_shell_loop(data_shell *datash);

/* read_line.c */
char *sya_read_line(int *i_eof);

/* split.c */
char *sya_swap_char(char *input, int bool);
void sya_add_nodes(sep_list **head_s, line_list **head_l, char *input);
void sya_go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
int sya_split_commands(data_shell *datash, char *input);
char **sya_split_line(char *input);

/* rep_var.c */
void sya_check_env(r_var **h, char *in, data_shell *data);
int sya_check_vars(r_var **h, char *in, char *st, data_shell *data);
char *sya_replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *sya_rep_var(char *input, data_shell *datash);

/* get_line.c */
void sya_bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t sya_get_line(char **lineptr, size_t *n, FILE *stream);

/* exec_line */
int sya_exec_line(data_shell *datash);

/* cmd_exec.c */
int sya_is_cdir(char *path, int *i);
char *_sya_which(char *cmd, char **_environ);
int sya_is_executable(data_shell *datash);
int sya_check_error_cmd(char *dir, data_shell *datash);
int sya_cmd_exec(data_shell *datash);

/* env1.c */
char *_sya_getenv(const char *name, char **_environ);
int sya_env(data_shell *datash);

/* env2.c */
char *sya_copy_info(char *name, char *value);
void sya_set_env(char *name, char *value, data_shell *datash);
int sya_setenv(data_shell *datash);
int sya_unsetenv(data_shell *datash);

/* sya_cd.c */
void sya_cd_dot(data_shell *datash);
void sya_cd_to(data_shell *datash);
void sya_cd_previous(data_shell *datash);
void sya_cd_to_home(data_shell *datash);

/* sya_cd_shell.c */
int sya_cd_shell(data_shell *datash);

/* get_builtin */
int (*sya_get_builtin(char *cmd))(data_shell *datash);

/* _exit.c */
int sya_exit_shell(data_shell *datash);

/* sya_stdlib.c */
int sya_get_len(int n);
char *sya_aux_itoa(int n);
int sya_atoi(char *s);

/* sya_error1.c */
char *sya_strcat_cd(data_shell *, char *, char *, char *);
char *sya_error_get_cd(data_shell *datash);
char *sya_error_not_found(data_shell *datash);
char *sya_error_exit_shell(data_shell *datash);

/* sya_error2.c */
char *sya_error_get_alias(char **args);
char *sya_error_env(data_shell *datash);
char *sya_error_syntax(char **args);
char *sya_error_permission(char **args);
char *sya_error_path_126(data_shell *datash);

/* get_error.c */
int sya_get_error(data_shell *datash, int eval);

/* get_sigint.c */
void sya_get_sigint(int sig);

/* sya_help.c */
void sya_help_env(void);
void sya_help_setenv(void);
void sya_help_unsetenv(void);
void sya_help_general(void);
void sya_help_exit(void);

/* sya_help2.c */
void sya_help(void);
void sya_help_alias(void);
void sya_help_cd(void);

/* get_help.c */
int sya_get_help(data_shell *datash);

#endif

