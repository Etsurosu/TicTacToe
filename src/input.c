#include	<time.h>
#include	<stdlib.h>

int	input(int pos[2])
{
  if (pos == NULL)
    {
      pos[0] = 0;
      pos[1] = 0;
    }
  
  pos[0]++;
  pos[1] = 0;
  return (0);
}
