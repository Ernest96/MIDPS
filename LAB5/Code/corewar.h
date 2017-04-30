/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcrivenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:38:56 by vcrivenc          #+#    #+#             */
/*   Updated: 2017/04/03 16:02:09 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "libft/libft.h"
# include "get_next_line.h"
# define AC_R     	"\x1b[31m"
# define AC_G	  	"\x1b[92m"
# define AC_Y	  	"\x1b[33m"
# define AC_B    	"\x1b[96m"
# define AC_M 		"\x1b[35m"
# define AC_C    	"\x1b[36m"
# define AC_RES  	"\x1b[0m"
#define CH_1 		char ** words; int8_t seek = 1;
#define CH 			CH_1 static int8_t flags[3] = {0, 0, 0};
#define IL  		static int temp = -1; static int j = -1;
#define OF1_1 		g_a[g_search[temp].loc] = (g_found[j].loc -
#define OF1 		OF1_1 g_search[temp].start) >> 8 & 0xff;
#define OF2_1 		g_a[g_search[temp].loc + 1] =
#define OF2 OF2_1 	(g_found[j].loc - g_search[temp].start) & 0xff;
#define OF23 		OF1; OF2;
#define OF3_1  		g_a[g_search[temp].loc] =
#define OF3 OF3_1	(g_found[j].loc - g_search[temp].start) >> 24 & 0xff;
#define OF4_1 		g_a[g_search[temp].loc + 1] =
#define OF4 OF4_1 	(g_found[j].loc - g_search[temp].start) >> 16 & 0xff;
#define OF34 		OF3; OF4;
#define CH_ARGS 	int8_t i = -1; obnulim();
#define ELSE_RET0	else return(0);
#define VAR 		int	fd; char *line; char **words;
#define MEMSIZE 	4096
#define IDX_MOD		512

typedef	struct		s_mat
{
	char	*laba;
	char	*instr;
	unsigned char acb;
	char	*arg1;
	char	*arg2;
	char	*arg3;
}					t_mat;

typedef struct 	s_pos
{
	int 	loc;
    int     start;
	char 	*str;
	int 	off;
}					t_pos;

typedef struct     s_proc
{
   int    reg[16];
   int     pc;
	int		ip;
   int     carry;
   int     live;
   int      end;
   int		cycles_to_wait;
   int     	begin;
}               t_proc;

typedef struct 		s_player
{
	t_proc proc[100];
	int pr_n;
	int nr;
	char *filename;
	char *name;
	int alive;
}					t_player;

typedef	struct	    s_instr
{
	unsigned char   code;
	unsigned char   acb;
	int    arg1;
	int    arg2;
	int    arg3;
}				    t_instr;


int 				g_dump;
int8_t 				g_num;
char 				*g_name;
char 				*g_comment;
char 				**g_sabl;
char 				**g_instr;
int8_t 				g_par[17];
int				 g_steps[17];
int					g_offset;
int					g_line;
t_mat 				*g_mat;
char 				*g_stack[100];
int 				g_size;
int 				g_top;
int					g_j[4];
int8_t 				g_can;
unsigned char       g_mem[MEMSIZE];
unsigned char		g_color[MEMSIZE];
unsigned char       g_a[MEMSIZE];
int                 g_i;
int                 g_ip;
int                 g_fi;
int                 g_si;
t_pos               g_search[100];
t_pos               g_found[100];
int                 test[100];
int                 p_test;
t_player 			g_arr[5];
unsigned char 		**g_order;
int    				g_winner;
void *mlx;
void *win;
int finishing;
int	g_tear;
int	g_pl;
int g_popo;
unsigned char g_poval;

int8_t	find_flag(char *s);
int8_t str_is_num(char *s);
void p_zero();
void	ft_check_players();
void	set_null();
unsigned char *ft_read_name(int i);
void	print_order(void);
void	insert_gamelife();
void	load();
void    init_steps(void);
void	generate_chars();
void waitFor (long secs);
void	print_box(int x, int y);
void	print_chars();
void	print_square(int x, int y, int color);
void	print_map(void);
void	change_state();
int	key_hook(int keycode, void *param);
int	loop_hook(void *param);
void            prepare_show(int juc, int pos, unsigned char val);
int					ft_start();
void				insert_labels(void);
int 				get_next_line(int fd, char **line);
void				dump(char *file);
int 				check_args(char **words, int8_t rez, int j);
int 				ft_num_words(char **words);
int 				is_return(int i);
void 				ft_find_label(void);
void				ft_init();
int 				good_line(int *fd, char **line);
int8_t	 			str_is_num(char *s);
void 				ft_diez(char *str);
int8_t	 			ft_check_instr(char *instr, int *i);
int8_t 				ft_only_space(char *line);
void				ft_check_letters(void);
int8_t				check_is_reg(char *s);
int8_t				check_direct(char *s);
int8_t				check_indirect(char *s);
void				ft_init_1(void);
void				ft_init_2(void);
void				ft_init_3(void);
void				check_label(char *arg);
void				set_instr(char *arg);
unsigned char 		set_acb(unsigned char acb);
void				set_indir(char *arg);
void				set_dir(char *arg);
void				set_arg(char *arg, int acb);
void				set_reg(char *arg);
void				set_label(char *label, int o);
unsigned char		get_acb(int8_t offset, int8_t type);
void				just_label(void);
void				ft_init_name_comment(int8_t *f, char *to_in, int8_t *seek, char *s);
void 				ft_first_check(int *fd);
void    			print(void);
int8_t 				ft_check_labe(char *labe);
void				set_args(int8_t ord, char *str, int8_t type);
void				print_struct(void);
void				set_label(char *label, int o);
int    				is_return(int i);
void    			codify(void);
void				ft_labe_error(const char *s);
void				set_dir(char *arg);
void				set_reg(char *arg);
void				print_struct(void);
void				obnulim(void);
void				print_struct2(void);
void				insert_labels(void);
void				ft_usage(void);
void				ft_check_stack(void);
int8_t 				ft_check_labe(char *labe);
void				set_indir(char *arg);
int8_t 				can_accept(int8_t order, int par, int inst);
void				set_instr(char *arg);
unsigned char		set_acb(unsigned char acb);
void				check_label(char *arg);
void				ft_invalid_input(void);
void				ft_comp_error(void);
void				ft_check_words_1(char **words, int8_t flag);
void				free_words(char **words);
void				ft_check_name_comment(char **s, int fd);
int8_t	 			ft_only_space(char *line);
void				ft_skip_spaces(int *fd);
int 				ft_check_dir(char **words, int8_t flag);
void				ft_check_ext(char *s);
int	expose_hook(void *param);
