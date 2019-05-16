#include	"../inc/my_putstr.h"

void    my_show_board(char board[3][3])
{
  int   i;
  int   j;
  char  tmp[7];

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
