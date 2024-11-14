
int ft_strlen(char *s)
{
	int i = 0;

	if (!s) return (0);
	while(s[i])
		i++;
	return (i);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	
	int len = ft_strlen(av[1]);
	int full_mask = (1 << len) - 1;

	int removed = 0;
	for(int i = full_mask; i > 0; i--)
	{
		removed = isbalance(av[1], i);
		if (removed > -1)
			break;
	}
	
}