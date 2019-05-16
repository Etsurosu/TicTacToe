#include	"../inc/my_show_board.h"
#include	"../inc/game.h"

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

int	init(int opt)
{
  char	board[3][3];

  init_board(board);
  my_show_board(board);
  game(board, opt);
  return (0);
}
