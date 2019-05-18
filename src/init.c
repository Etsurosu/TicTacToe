#include	"../inc/game.h"
#include	"../inc/curses.h"

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

int	init(int opt, WIN *win)
{
  //char	board[3][3];

  init_board(win->board);
  init_curses(win);
  game(win->board, opt, win);
  endwin();
  return (0);
}
