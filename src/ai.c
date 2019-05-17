#include	<stdbool.h>
#include	<stdlib.h>
#include	"../inc/ai.h"

void		set_pos(int pos[2], int y, int x)
{
  pos[0] = y;
  pos[1] = x;
  return ;
}

int		is_board_empty(char board[3][3])
{
  int		i;
  int		j;

  i = 0;
  while (i < 3)
    {
      j = 0;
      while (j < 3)
	if (board[i][j++] != ' ')
	  return (false);
      i++;
    }
  return (true);
}

bool		try_win(char board[3][3], int pos[2], char letter)
{
  return (true);
}

bool		try_deny(char board[3][3], int pos[2], char letter)
{
  return (true);
}

void		ai(char board[3][3], int pos[2], char letter)
{
  if (is_board_empty(board))
    return (set_pos(pos, 0, 0));
  /*  if (try_win(board, pos, letter))
    return ;
  if (try_deny(board, pos, letter))
  return ;*/
  pos[0] = rand() % 3;
  pos[1] = rand() % 3;
  return ;
}
