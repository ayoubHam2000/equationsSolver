#include <stdlib.h>

int		is_there_char_charset(char str, char *charset){
	int i;

	i = -1;
	while (charset[++i])
		if (str == charset[i])
			return (1);
	return (0);
}

char	*cpy(char *dest, char *src, int n){
	int i;

	i = -1;
	while (++i < n)
		dest[i] = src[i];
	dest[n] = '\0';
	return (dest);
}

char	**words(char *str, char *charset){
	char	**tab;
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i])
    {
		if (!is_there_char_charset(str[i], charset) && str[i])
        {
			words++;
			while (!is_there_char_charset(str[i], charset) && str[i])
				i++;
        }
		while (is_there_char_charset(str[i], charset) && str[i])
			i++;
    }
	tab = malloc(sizeof(char *) * (words + 1));
	return (tab);
}

void	characters(char **tab, char *p, char *charset){
	int j;
	int count;

	j = -1;
	count = 0;
	while (1)
    {
		while (is_there_char_charset(p[0], charset) && p[0])
			p++;
		while (!is_there_char_charset(p[count], charset) && p[count] != 0)
			count++;
		if (*p)
        {
			tab[++j] = malloc(count + 1);
			cpy(tab[j], p, count);
        }
		while (count > 0)
        {
			count--;
			p++;
        }
		if (!p[0])
			break ;
    }
	tab[++j] = 0;
}

char	**ft_split(char *str, char *charset){
	char **tab;
	char *p;

	p = str;
	tab = words(str, charset);
	characters(tab, p, charset);
	return (tab);
}
