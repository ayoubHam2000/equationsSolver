#include "tools/bib.h"

void newPoly(char *str){
	float result;
	List *newPoly;

	newPoly = buildPoly(str);
	displayPoly(newPoly);
	result = solvePoly(newPoly, 10, 100);
	printf("la result est : %.3f \n", result);
}

int main(int ac, char **av)
{
	newPoly(av[1]);
	getchar();
	return 0;
}