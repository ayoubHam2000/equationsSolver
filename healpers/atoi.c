void	filter(char *str, int *bigin, int *fin){
	int i;
	int b;
	int stop;

	i = 0;
    if (str[i] == '+' || str[i] == '-')
		i++;
    while (str[i] != '\0' && str[i] == ' ')
		i++;
    if (str[i] < '0' || str[i] > '9')
		stop = 1;
    else
    {
		b = i;
        while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
        {
			i++;
        }
        *bigin = b;
        *fin = i;
    }
}

int		ft_atoi(char *str){
    int bigin;
	int fin;
	int i;
	int result;
	int mult;

	filter(str, &bigin, &fin);
	i = fin;
	result = 0;
	mult = 1;
    while (--i >= bigin)
    {
        result = result + ((str[i] - 48) * mult);
        mult = mult * 10;
    }
    if (str[0] == '-')
        result = -result;
    return (result);
}
