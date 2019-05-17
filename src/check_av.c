int	check_av(char *av)
{
  if (av[1] == '\0' && av[0] > '0' && av[0] < '3')
    return (av[0] - '0');
  return (0);
}
