/*
** header.h for my_select in /home/champi_t/rendu/PSU_2015_my_select
** 
** Made by theo champion
** Login   <champi_t@epitech.net>
** 
** Started on  Tue Dec  1 11:49:42 2015 theo champion
** Last update Sun Dec 13 13:31:17 2015 theo champion
*/

#include <ncurses/curses.h>
#include <stdlib.h>

typedef struct	s_list
{
  char		*data;
  int		selected;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef struct	s_ctrl
{
  struct s_list	*head;
  struct s_list	*tail;
}		t_ctrl;

typedef struct	s_pos
{
  int		max_row;
  int		max_col;
  int		row;
  int		col;
  int		longer;
}		t_pos;

char	*find_env(char *, char **);
char	*get_info(char **, int, int);
t_ctrl	*fill_list(int, char **);
t_ctrl	*init_control(void);
void	add_elem_end(t_ctrl *, char *);
int	del_elem(t_ctrl *, t_list *);
void	print_list(t_ctrl *);
int	print_menu(WINDOW *, t_ctrl *, t_list *);
t_list	*elem_prev(t_ctrl *, t_list *);
t_list	*elem_next(t_ctrl *, t_list *);
void	print_elem(WINDOW *, int, int, t_list *);
t_list	*inverse_status(t_ctrl *, t_list *);
t_pos	*init_pos(void);
void	where_to_print(t_list *, t_pos *);
void	print_selected(WINDOW *, t_list *, t_pos *, t_list *);
int	handle_cases(t_list *, t_ctrl *, WINDOW *);
void	return_to_shell(t_ctrl *);
void	my_putchar(char);
void	my_putstr(char *);
int	my_strlen(char *);
char	*mystrcpy(char *, char *);
int	check_param(int, char *);
