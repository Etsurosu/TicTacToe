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

  if ((ret = check_lines(board)) != ' ') {
    write (1, "fdp\n", 4);
    return (ret);
  }
  else if ((ret = check_columns(board)) != ' ')
    return (ret);
  else if (ret = check_diags(board) != ' ')
    return (ret);
  return (check_full(board));
}

int		show_winner(int start, char winner, int opt)
{
  if (start == 0 && winner == 'x')
    return (my_putstr("Player1 is the winner\n"));
  else if (winner == 'o')
    return (my_putstr(opt == 1 ? "Player2 is the winner\n" : "AI is the winner\n"));
  return (my_putstr("Draw\n"));
}

int		show_turn(int to_play, int opt)
{
  if (to_play == 0)
    return (my_putstr("Player1 it\' your turn to play\n"));
  if (opt == 1)
    return (my_putstr("Player2 it\' your turn to play\n"));
  return (my_putstr("AI\'s turn\n"));
}

int		game(char board[3][3], int opt)
{
  time_t	time_init;
  int		start;
  int		to_play;
  int		pos[2];
  char		ret;

  srand((unsigned)time(&time_init));
  start = rand() % 2;
  to_play = start;
  while ((ret = check_win(board)) == ' ')
    {
      //Faudra refaire cette fonction en ncurses
      my_show_board(board);
      show_turn(to_play, opt);
      //Need l'input du joueur ici, a stocker dans pos, pos[0] = axe y, pos[1] = axe x
      if (opt == 1 || to_play == 0)
	input(pos);
      else
	ai(board, pos, start == 1 ? 'x' : 'o');
      if (board[pos[0]][pos[1]] == ' ')
	{
	  board[pos[0]][pos[1]] = (start == to_play++) ? 'x' : 'o';
	  to_play %= 2;
	}
      else
	my_putstr("You can't play here\n"); //si t'es chaud en ncurses aussi ;)
    }
  // si tu te sens chaud tu peux refaire cette fonction en ncurses
  show_winner(start, ret, opt);
  return (0);
}
