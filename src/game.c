#include	<time.h>
#include	<stdlib.h>
#include	"../inc/my_putstr.h"
#include	"../inc/my_show_board.h"
#include	"../inc/ai.h"
#include	"../inc/input.h"

char		check_lines(char board[3][3])
{
  int		i;
  int		j;
  char		first;
  
  i = 0;
  j = 0;
  while (i < 3)
    {
      j = 0;
      first = board[i][j++];
      while (j < 3 && first != ' ' && first == board[i][j])
	j++;
      if (j == 3)
	return (first);
      i++;
    }
  return (' ');
}

char		check_columns(char board[3][3])
{
  int		i;
  int		j;
  char		first;

  i = 0;
  j = 0;
  while (i < 3)
    {
      j = 0;
      first = board[j++][i];
      while (j < 3 && first != ' ' && first == board[j][i])
	j++;
      if (j == 3)
	return (first);
      i++;
    }
  return (' ');  
}

char		check_diags(char board[3][3])
{
  char		first;

  first = board[1][1];
  if (first != ' ' &&
      ((first == board[0][0] && first == board [2][2]) ||
       (first == board[0][2] && first == board[2][0])))
    return (first);
  return (' ');
}

char		check_full(char board[3][3])
{
  int		i;
  int		j;

  i = 0;
  while (i < 3)
    {
      j = 0;
      while (j < 3 && board[i][j] != ' ')
	j++;
      if (j != 3)
	return (' ');
      i++;
    }
  return ('!');
}

char		check_win(char board[3][3])
{
  char		ret;

  if ((ret = check_lines(board)) != ' ')
    return (ret);
  else if ((ret = check_columns(board)) != ' ')
    return (ret);
  if ((ret = check_diags(board)) != ' ')
    return (ret);
  return (check_full(board));
}

int		show_winner(int start, char winner, int opt, WIN *win)
{
  if (start == 0 && winner == 'x' || start == 1 && winner == 'o')
    mvprintw,(win->starty - 2, win->startx - 3, "Player1 is the winner\n");
  else if (start == 0 && winner == 'o')
    mvprintw(win->starty - 2, win->startx - 3, opt == 1 ? "Player2 is the winner\n" : "AI is the winner\n");
  else
    mvprintw(win->starty - 2, win->startx - 3, "Draw\n");
  if (input(&opt, win) == -1)
    return (0);
  return (0);
}

int		show_turn(int to_play, int opt, WIN *win)
{
  if (to_play == 0)
    {
      mvprintw(win->starty - 2, win->startx - 3, "Player1 it\'s your turn to play\n");
      return (0);
    }
  if (opt == 1)
    return (mvprintw(win->starty - 2, win->startx - 3, "Player2 it\'s your turn to play\n"));
  return (mvprintw(win->starty - 2, win->startx - 3, "AI\'s turn\n"));
}

int		game(char board[3][3], int opt, WIN *win)
{
  time_t	time_init;
  int		start;
  int		to_play;
  int		pos[2];
  char		ret;

  srand((unsigned)time(&time_init));
  start = rand() % 2;
  to_play = start;
  while ((ret = check_win(win->board)) == ' ')
    {
      show_turn(to_play, opt, win);
      if (opt == 1 || to_play == 0)
	{
	  if (input(pos, win) == -1)
	    return (0);
	}
      else
	ai(win->board, pos, start == 1 ? 'x' : 'o');
      refresh();
      if (win->board[pos[0]][pos[1]] == ' ')
	{
	  win->board[pos[0]][pos[1]] = (start == to_play++) ? 'x' : 'o';
	  to_play %= 2;
	}
      else
	mvprintw(0, 0, "You can't play here\n");
      refresh();
    }
  show_winner(start, ret, opt,win);
  return (0);
}
