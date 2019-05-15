int	check_av(char *av)
{
  if (av[1] == '\0' && av[0] >= '0' && av[0] <= '9')
    return (av[1] - '0');
}
