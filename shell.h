#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>

#define CONV_LW	1
#define CONV_UN	2
#define G_L		0
#define COM_O	1
#define COM_N	0
#define COM_C	3
#define COM_A	2
#define BUFF_R  1024
#define BUFF_F  -1
#define BUFF_W  1024
#define HIST_F	".shell_history"
#define HIST_M	4096


extern char **environ;


/**
 * str_linked_list - str_linked_list
 * @struct_no: number
 * @struct_str: string
 * @struct_next: pointer
 */
typedef struct str_linked_list
{
	int struct_no;
	char *struct_str;
	struct str_linked_list *struct_next;
} list_struct;

/**
 *struct struct_information - struct struct_information
 *@struct_count: struct_count
 *@struct_num: struct_num
 *@struct_count_f: struct_count_f
 *@struct_f_name: struct_f_name
 *@struct_env: struct_env
 *@struct_env_copy: struct_env_copy
 *@struct_als: struct_als
 *@struct_buff: struct_buff
 *@struct_buff_t: struct_buff_t
 *@struct_f_r: struct_f_r
 *@struct_change_env: struct_change_env
 *@struct_status: struct_status
 *@struct_his: struct_his
 *@struct_hist_c: struct_hist_c
 *@struct_path: struct_path
 *@struct_argc: struct_argc
 *@struct_arg: struct_arg
 *@struct_argv: struct_argv
 */
typedef struct struct_information
{
	unsigned int struct_count;
	int struct_num;
	int struct_count_f;
	char *struct_f_name;
	list_struct *struct_env;
	char **struct_env_copy;
	list_struct *struct_als;
	char **struct_buff;
	int struct_buff_t;
	int struct_f_r;
	int struct_change_env;
	int struct_status;
	list_struct *struct_his;
	int struct_hist_c;
	char *struct_path;
	int struct_argc;
	char *struct_arg;
	char **struct_argv;
} information_struct;

#define INFORM_INI \
{0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL, 0, \
	NULL, 0, NULL, NULL}

/**
 *str_builtin - builtin
 *@struct_type: struct_type
 *@struct_function: struct_function
 */
typedef struct str_builtin
{
	char *struct_type;
	int (*struct_function)(information_struct *);
} builtin_struct;


/* 0-str_func.c */

char *begin_with(const char *, const char *);
int string_length(char *);
int string_compare(char *, char *);
char *string_duplicate(const char *);
char *string_concat(char *, char *);
char *string_concat2(char *, char *, int);
char *string_copy(char *, char *);
char *string_copy2(char *, char *, int);
void string_print(char *);
int string_print2(char);
char *string_locate(char *, char);
char **string_split(char *, char *);
char **string_split2(char *, char);

/* 1-memo_func */
int memory_free_pointer(void **);
void memory_free(char **);
void *memory_loc(void *, unsigned int, unsigned int);
char *memory_set(char *, char, unsigned int);

/* 2-gen_func.c */
int check_alpha(char);
int char_delim(char, char *);
int shell_status(information_struct *);
int str_to_int(char *);
void remove_comments(char *);
void print_err(information_struct *, char *);
int print_dec(int, int);
char *convert_no(long int, int, int);


/* 3-emul_func.c */
int change_dir(information_struct *);
int alias_mimics(information_struct *);
int show_history(information_struct *);
int shell_exit(information_struct *);

/* 4-env_func.c module */
int init_env(information_struct *, char *, char *);
int populate_env(information_struct *);
int set_env(information_struct *);
char *get_env(information_struct *, const char *);
int unset_env(information_struct *);
char **return_env(information_struct *);
int remove_env(information_struct *, char *);
int print_env(information_struct *);

/* 5-chain_fun.c */
int vars_rep(information_struct *);
void chain_check(information_struct *, char *, size_t *, size_t, size_t);
int chain_status(information_struct *, char *, size_t *);
int alias_rep(information_struct *);
int str_rep(char **, char *);

/* 6-io_func.c */
int history_build(information_struct *info, char *buf, int linecount);
int history_read(information_struct *info);
char *history_get_file(information_struct *info);
int history_write(information_struct *info);
int history_renumbers(information_struct *info);

/* 7-getline_func.c module */
ssize_t input_get(information_struct *);
int line_get(information_struct *, char **, size_t *);
void handler_int(int);

/* 8-hsh_func.c */
int hsh_func(information_struct *, char **);
int cmd_builtin_find(information_struct *);
void cmd_find(information_struct *);
void cmd_f(information_struct *);

/* 9-info_func.c module */
void info_free(information_struct *, int);
void init_info(information_struct *);
void info_set(information_struct *, char **);

/* 10-path_func.c */
char *get_path(information_struct *, char *, char *);
char *char_duplicate(char *, int, int);
int file_status(information_struct *, char *);

/* 11-str_err_func.c */
int put_file_desc(char c, int fd);
int put_echar(char);
int print_file_desc(char *str, int fd);
void put_estring(char *);

/* string_list.c module */
ssize_t node_index(list_struct *, list_struct *);
list_struct *node_end(list_struct **, const char *, int);
int node_delete_with_index(list_struct **, unsigned int);
void free_allnodes(list_struct **);
size_t strlist_print(const list_struct *);
size_t length_list(const list_struct *);
char **convert_lis_to_str(list_struct *);
size_t linklist_print(const list_struct *);
list_struct *startwith_node(list_struct *, char *, char);
list_struct *node_put(list_struct **, const char *, int);

#endif
