/*
** cases.c for my_select in /home/champi_t/rendu/PSU_2015_my_select
** 
** Made by theo champion
** Login   <champi_t@epitech.net>
** 
** Started on  Thu Dec  3 13:40:08 2015 theo champion
** Last update Wed Dec  9 19:49:22 2015 theo champion
*/

#include "header.h"

t_list	*inverse_status(t_ctrl *ctrl, t_list *elem)
{
  if (elem->selected == 0)
    elem->selected = 1;
  else
    elem->selected = 0;
  elem = elem_next(ctrl, elem);
}

t_list	*elem_prev(t_ctrl *ctrl, t_list *elem)
{
  if (elem->prev == NULL)
    elem = ctrl->tail;
  else
    elem = elem->prev;
  return (elem);
}

t_list	*elem_next(t_ctrl *ctrl, t_list *elem)
{
  if (elem->next == NULL)
    elem = ctrl->head;
  else
    elem = elem->next;
  return (elem);
}

void	print_elem(WINDOW *menu_win, int row, int col, t_list *elem)
{
  if (elem->selected == 1)
    {
      wattron(menu_win, A_REVERSE);
      mvwprintw(menu_win, row, col, "%s", elem->data);
      wattroff(menu_win, A_REVERSE);
    }
  else
    mvwprintw(menu_win, row, col, "%s", elem->data);
}
