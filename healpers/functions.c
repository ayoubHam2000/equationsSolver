#include "../tools/bib.h"

void    newERROR(char *message){
    printf("ERROR : %s\n", message );
}

int		str_len(char *str){
	int i;

	i = 0;
	while(str[i] != 0)
		i++;
	return (i);
}

float	ft_abs(float a){
    if(a < 0){
        return -a; 
	}
	return a;
}

int ft_max(int a, int b){
    return a > b ? a : b;
}