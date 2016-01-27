/*
** list.c for my_select in /home/champi_t/rendu/PSU_2015_my_select
** 
** Made by theo champion
** Login   <champi_t@epitech.net>
** 
** Started on  Tue Dec  1 15:46:12 2015 theo champion
** Last update Mon Jan 25 01:52:11 2016 theo champion
*/

#include "header.h"

t_ctrl		*fill_list(int argc, char **argv)
{
  int		i;
  t_ctrl	*ctrl;

  i = 1;
  ctrl = init_control();
  while (i < argc)
    add_elem_end(ctrl, argv[i++]);
  return (ctrl);
}

void		add_elem_end(t_ctrl *ctrl, char *data)
{
  t_list	*elem;

  elem = malloc(sizeof(t_list));
  elem->data = malloc(sizeof(char) * my_strlen(data));
  my_strcpy(elem->data, data);
  elem->selected = 0;
  if (ctrl->tail == NULL)
    {
      elem->prev = NULL;
      ctrl->head = elem;
      ctrl->tail = elem;
    }
  else
    {
      elem->prev = ctrl->tail;
      ctrl->tail->next = elem;
      elem->next = NULL;
      ctrl->tail = elem;
    }
}

int	del_elem(t_ctrl *ctrl, t_list *elem)
{
  if (elem == ctrl->head && elem == ctrl->tail)
    return (1);
  else if (elem == ctrl->head)
    {
      elem->next->prev = NULL;
      ctrl->head = elem->next;
    }
  else if (elem == ctrl->tail)
    {
      elem->prev->next = NULL;
      ctrl->tail = elem->prev;
    }
  else if (elem != ctrl->head && elem != ctrl->tail)
    {
      elem->prev->next = elem->next;
      elem->next->prev = elem->prev;
    }
  free(elem);
  return (0);
}

t_ctrl		*init_control(void)
{
  t_ctrl	*ctrl;

  ctrl = malloc(sizeof(t_ctrl));
  ctrl->head = NULL;
  ctrl->tail = NULL;
  return (ctrl);
}
