#ifndef PARSER_H
#define PARSER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "cub3d.h" 

typedef struct s_color_c
{
    int c1;
    int c2;
    int c3;
} t_color_c;

typedef struct s_color_f
{
    int f1;
    int f2;
    int f3;
} t_color_f;

typedef struct s_parser
{
    t_list  *list;
    t_list  *file;
    char **map;
    char *no;
    char *so;
    char *we;
    char *ea;
    int error;
    t_color_c ccolor;
    t_color_f fcolor;
    int len_map;
    char player;
    int count;
    int count_we;
    int count_so;
    int count_ea;
    int count_no;
    int incr;
    int count_player;
} t_parser;

// int map(t_parser *parser, int fd);
int check_file(char *str);
void line_by_line(char *file, t_parser *parser);
void map(t_parser *parser);
void check_tab(t_parser *parser);
void free_cub(t_parser *parser,int i);
void initialize_value(t_parser *parser);
void part_error();
int check_file(char *str);
int check_extension(char *str);
void check_color_and_floor_digit(t_parser *parser);
int check_wall(char *str);
void check_another_chara(char *str);
void check_file_line(t_parser *parser);
void check_char(char *str, t_parser *parser);
char *take_path(t_parser *parser, char *str);
void check_rep_path(t_parser *parser);
void take_color(t_parser *parser, char *str, char c);
void take_string_color(t_parser *parser, char *str, char c);
void char_to_int(t_parser *parser, char *str, char c, int j);
void cieling_struct(t_parser *parser, char *str, char c, int j);
void take_string_color(t_parser *parser, char *str, char c);
void	take_color(t_parser *parser, char *str, char c);
void	check_last_first_line(t_parser *parser);
int	check_if_wall(char *str);
int	check_char_map(char *str, t_parser *parser);
void	parser(char *file, t_var *var);
char    **put_twod_array(t_list *lst);
char	*char_join(char *str, char c);
#endif
