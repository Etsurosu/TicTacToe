#include	"../inc/check_av.h"
#include	"../inc/init.h"
#include	"../inc/my_putstr.h"
#include	"../inc/input.h"
#include	"../inc/curses.h"
#include	<time.h>

int	main(int ac, char **av)
{
  int	ret;
  WIN	win;

  if (ac == 2 && (ret = check_av(av[1])))
    return (init(ret, &win));
  my_putstr("Usage: [difficulty level]\n\t1 means player vs player\n\t2 means player vs AI\n");
  return (0);
}
