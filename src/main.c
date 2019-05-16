#include	"../inc/check_av.h"
#include	"../inc/init.h"
#include	"../inc/my_putstr.h"

int	main(int ac, char **av)
{
  int	ret;

  if (ac == 2 && (ret = check_av(av[1]))) //TO_CHECK
    return (init(ret));
  my_putstr("Usage: [difficulty level]\n\t1 means player vs player\n\t2 means player vs AI\n");
  return (0);
}
