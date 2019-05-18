#include	"../inc/curses.h"
#include	"../inc/my_show_board.h"
#include	"string.h"
#include	"stdlib.h"
#include	"unistd.h"

void init_win_params(WIN *p_win)
{
  p_win->height = 5;
  p_win->width = 5;
  p_win->prev = ' ';
  p_win->starty = (LINES - p_win->height)/2;	
  p_win->startx = (COLS - p_win->width)/2;
  p_win->posx = 0;
  p_win->posy = 0;
}

void create_box(WIN *p_win, bool flag)
{
  int i, j;
  int x, y, w, h;

  x = p_win->startx;
  y = p_win->starty;
  w = p_win->width;
  h = p_win->height;

  if(flag == TRUE)
    {
      j = -1;
      while (j++ < 5)
	{
	  i = -1;
	  if (j % 2)
	    while(++i < 5)
	      mvaddch(y + j, x + i, '-');
	  else
	    while (++i < 5)
	      if (i % 2)
		mvaddch(y + j, x + i, '|');
	      else
		mvaddch(y + j, x + i, p_win->board[j / 2][i / 2]);
	}
    }
  else
    for(j = y; j <= y + h; ++j)
      for(i = x; i <= x + w; ++i)
	mvaddch(j, i, ' ');
  refresh();
}

void	move_in_board(WIN *p_win, int x, int y)
{
  int ox = p_win->posx, oy = p_win->posy;

  
  if (y != 0 && (ox + y) <= 2 && (ox + y) >= 0){
    ox += y;
  }
  else if (x != 0 && (oy + x) <= 2 && (oy + x) >= 0){
    oy += x;
  }
  p_win->posx = ox;
  p_win->posy = oy;
}

void	init_curses(WIN *win)
{
  initscr();			/* Start curses mode 		*/
  start_color();			/* Start the color functionality */
  cbreak();			/* Line buffering disabled, Pass on
				 * everty thing to me 		*/
  keypad(stdscr, TRUE);		/* I need that nifty F1 	*/
  noecho();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  mvprintw(0, 0, "Press Escape to leave");

  /* Initialize the window parameters */
  init_win_params(win);

  attron(COLOR_PAIR(1));
  refresh();
  attroff(COLOR_PAIR(1));
  
  create_box(win, TRUE);
  move_in_board(win, 0, 0);
}
