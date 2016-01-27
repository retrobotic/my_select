/*
** print_menu.c for my_select in /home/champi_t/rendu/PSU_2015_my_select
** 
** Made by theo champion
** Login   <champi_t@epitech.net>
** 
** Started on  Thu Dec  3 13:48:14 2015 theo champion
** Last update Sun Dec 13 13:32:25 2015 theo champion
*/

#include "header.h"

int		print_menu(WINDOW *menu_win, t_ctrl *ctrl, t_list *selected)
{
  t_list	*elem;
  t_pos		*pos;
  int		i;

  i = 0;
  pos = init_pos();
  elem = ctrl->head;
  getmaxyx(menu_win, pos->max_row, pos->max_col);
  wclear(menu_win);
  while (elem)
    {
      where_to_print(elem, pos);
      print_selected(menu_win, elem, pos, selected);
      i = i + 1;
      pos->row = pos->row + 1;
      elem = elem->next;
    }
  if ((pos->col + pos->longer) >= pos->max_col)
    return (1);
  wrefresh(menu_win);
  return (0);
}

void	where_to_print(t_list *elem, t_pos *pos)
{
  if (my_strlen(elem->data) > pos->longer)
    pos->longer = my_strlen(elem->data);
  if (pos->row >= pos->max_row)
    {
      pos->col = pos->col + (pos->longer + 2);
      pos->row = 0;
      pos->longer = 0;
    }
}

void	print_selected(WINDOW *menu_win, t_list *elem, t_pos *pos, t_list *sel)
{
  if (elem == sel)
    {
      wattron(menu_win, A_UNDERLINE);
      print_elem(menu_win, pos->row, pos->col, elem);
      wattroff(menu_win, A_UNDERLINE);
    }
  else
    print_elem(menu_win, pos->row, pos->col, elem);
}

t_pos	*init_pos(void)
{
  t_pos	*pos;

  pos = malloc(sizeof(t_pos));
  pos->row = 0;
  pos->col = 0;
  pos->longer = 0;
  return (pos);
}
