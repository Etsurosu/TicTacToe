#include	<time.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>

int	input(int pos[2])
{
  int	size = 0;
  char str[2];

  printf("Ou jouer ? ->");
  read(0, str, 2);
  if (((str[0] - '0') >= 1 && (str[0] - '0') <= 9) && str[1] == '\n')
    printf("%d\n", str[0] - '0');
  else {
    printf("out of range = [%s]\n", str);
    return (-1);
  }

  pos[0] = (str[0] - '1') / 3;
  pos[1] = (str[0] - '1') % 3;

  return (0);
}
