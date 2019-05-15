#include	"../inc/my_putstr.h"

void	init_board(char board[3][3])
{
  int	i;
  int	j;

  i = 0;
  while (i < 3)
    {
      j = 0;
      while (j < 3)
	board[i][j++] = ' ';
      i++;
    }
  return ;
}

void	my_show_board(char board[3][3])
{
  int	i;
  int	j;
  char	tmp[7];

  j = -1;
  tmp[6] = '\0';
  tmp[5] = '\n';
  while (++j < 5)
    {
      i = -1;
      if (j % 2)
	while (++i < 5)
	  tmp[i] = '-';
      else
	while (++i < 5)
	  if (i % 2)
	    tmp[i] = '|';
	  else
	    tmp[i] = board[j / 2][i / 2];
      my_putstr(tmp);
    }
  return ;
}

int	init(int opt)
{
  char	board[3][3];

  init_board(board);
  my_show_board(board);
  return (0);
}
