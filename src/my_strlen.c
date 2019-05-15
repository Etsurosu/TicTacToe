int	my_strlen(char *str)
{
  char	*tmp;

  tmp = str;
  while (tmp && *tmp)
    tmp++;
  return (tmp - str);
}
