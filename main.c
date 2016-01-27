/*
** main.c for my_select in /home/champi_t/rendu/PSU_2015_my_select
** 
** Made by theo champion
** Login   <champi_t@epitech.net>
** 
** Started on  Mon Nov 30 18:42:58 2015 theo champion
** Last update Mon Jan 25 01:51:28 2016 theo champion
*/

#include "header.h"

int		main(int argc, char **argv, char **env)
{
  WINDOW	*menu_win;
  t_ctrl	*ctrl;
  t_list	*elem;
  int		aborted;

  if (check_param(argc, "There must be at least one parameter.") == 1)
    return (1);
  newterm(find_env("TERM=", env), stderr, stdin);
  clear();
  noecho();
  cbreak();
  curs_set(0);
  menu_win = newwin(0, 0, 0, 0);
  keypad(menu_win, TRUE);
  ctrl = fill_list(argc, argv);
  elem = ctrl->head;
  print_menu(menu_win, ctrl, elem);
  aborted = handle_cases(elem, ctrl, menu_win);
  refresh();
  endwin();
  if (aborted == 0)
    return_to_shell(ctrl);
  return (0);
}

int	handle_cases(t_list *elem, t_ctrl *ctrl, WINDOW *menu_win)
{
  int	c;

  while (42)
    {
      c = wgetch(menu_win);
      if (c == KEY_UP)
        elem = elem_prev(ctrl, elem);
      else if (c == KEY_DOWN)
        elem = elem_next(ctrl, elem);
      else if (c == 32)
        elem = inverse_status(ctrl, elem);
      else if (c == KEY_BACKSPACE || c == 127 || c == KEY_DC)
        {
          if (del_elem(ctrl, elem) == 1)
            return (1);
          elem = elem_next(ctrl, elem);
        }
      else if (c == 10)
        return (0);
      else if (c == 27)
        return (1);
      if (print_menu(menu_win, ctrl, elem) == 1)
        return (1);
    }
}

void		return_to_shell(t_ctrl *ctrl)
{
  t_list	*elem;
  int		space;

  elem = ctrl->head;
  space = 0;
  while (elem)
    {
      if (elem->selected == 1)
        {
          if (space == 1)
            my_putchar(' ');
          my_putstr(elem->data);
          space = 1;
        }
      elem = elem->next;
    }
}

char	*find_env(char *str, char **env)
{
  int	index;
  int	count;
  int	cursor;
  char	*temp;

  cursor = 0;
  index = 0;
  while (env[index])
    {
      count = 0;
      while (env[index][count] == str[count] && str[count])
        count = count + 1;
      if (!str[count])
        {
          temp = get_info(env, index, count);
          return (temp);
        }
      index = index + 1;
    }
  return (NULL);
}

char	*get_info(char **env, int index, int count)
{
  int	cursor;
  char	*temp;

  cursor = 0;
  if ((temp = malloc(sizeof(char) * my_strlen(env[index]))) == NULL)
    return (NULL);
  while (env[index][count])
    temp[cursor++] = env[index][count++];
  temp[cursor] = 0;
  return (temp);
}
