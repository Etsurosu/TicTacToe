#ifndef		CURSES_H_
 #define	CURSES_H_

#include <ncurses.h>

typedef struct _win_border_struct {
  chtype 	ls, rs, ts, bs, 
    tl, tr, bl, br;
}WIN_BORDER;

typedef struct _WIN_struct {

  int startx, starty;
  int height, width;
  int posx, posy;
  char prev;
  char	board[3][3];
  WIN_BORDER border;
}WIN;


void	init_curses(WIN *win);
void create_box(WIN *p_win, bool flag);
void	move_in_board(WIN *p_win, int x, int y);

#endif		/* __CURSES_H__ */
