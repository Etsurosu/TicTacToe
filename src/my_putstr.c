#include	<unistd.h>
#include	"../inc/my_strlen.h"

int	my_putstr(char *str)
{
  return (write(1, str, my_strlen(str)));
}
