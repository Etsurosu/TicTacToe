#include	"../inc/curses.h"
#include	"../inc/my_show_board.h"
#include	"string.h"
#include	"stdlib.h"
#include	"unistd.h"

int	input(int pos[2], WIN *win)
{
  int ch;
  
  while((ch = getch()) != 27)
    {
      switch(ch)
      	{
	case KEY_LEFT:
	  create_box(win, FALSE);
	  move_in_board(win, -1, 0);
	  //	  --win.startx;
	  create_box(win, TRUE);
	  break;
      	case KEY_RIGHT:
      	  create_box(win, FALSE);
	  move_in_board(win, 1, 0);
      	  //++win.startx;
      	  create_box(win, TRUE);
      	  break;
      	case KEY_UP:
      	  create_box(win, FALSE);
	  move_in_board(win, 0, -1);
	  //      	  --win.starty;
      	  create_box(win, TRUE);
      	  break;
      	case KEY_DOWN:
      	  create_box(win, FALSE);
	  move_in_board(win, 0, 1);
	  //      	  ++win.starty;
      	  create_box(win, TRUE);
      	  break;
	case ' ':
	  pos[0] = win->posx;
	  pos[1] = win->posy;
	  return (0);
      	}
      mvaddch(win->starty + (win->posx * 2), win->startx + (win->posy * 2), '*');
      refresh();
    }
  return (-1);
}

/* int	input(int pos[2]) */
/* { */
/*   int	size = 0; */
/*   char str[2]; */
  
/*   read(0, str, 2); */
/*   if (((str[0] - '0') >= 1 && (str[0] - '0') <= 9) && str[1] == '\n') */
/*     printf("%d\n", str[0] - '0'); */
/*   else { */
/*     printf("Ou jouer ? ->"); */
/*     return (input(pos)); */
/*   } */

/*   pos[0] = (str[0] - '1') / 3; */
/*   pos[1] = (str[0] - '1') % 3; */

/*   return (0); */
/* } */
