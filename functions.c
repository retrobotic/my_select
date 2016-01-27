/*
** functions.c for my_select in /home/champi_t/select_backup
** 
** Made by theo champion
** Login   <champi_t@epitech.net>
** 
** Started on  Thu Dec 10 15:30:39 2015 theo champion
** Last update Sun Dec 13 13:03:18 2015 theo champion
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int	my_strlen(char *str)
{
  int	len;

  len = 0;
  while (str[len] != '\0')
    {
      len = len + 1;
    }
  return (len);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

int	check_param(int argc, char *error)
{
  if (argc < 2)
    {
      write(2, error, my_strlen(error));
      return (1);
    }
  return (0);
}
