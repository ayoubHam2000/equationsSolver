#include "../tools/bib.h"

List *buildPoly(char *thePoly){
    char    **numbers;
    char    **splitPoly;
    List    *poly;
    Monome  *newMonome;

    poly = listInit(poly);
    splitPoly = ft_split(thePoly, "+");
    while(*splitPoly != 0){
        newMonome = (Monome *)malloc(sizeof(Monome));
        numbers = ft_split(*splitPoly, "x*");
        newMonome->coef = ft_atoi(numbers[0]);
        newMonome->expo = ft_atoi(numbers[1]);
        listAdd(poly, (void *)newMonome);
        splitPoly++;
    }

    return poly;
}

void displayPoly(List *poly){
    Element *temp;
    Monome  *theMonome;

    temp = poly->firstElement;
    if(temp == NULL){
        printf("0\n");
    }
    while(temp != NULL){
        theMonome = (Monome *)(temp->info);
        printf("%dx^%d", theMonome->coef, theMonome->expo);
        temp = temp->next;
        if(temp == NULL){ printf("\n"); }else{ printf(" + "); }
    }
}

float calculPoly(List *poly, float x){
    Element *temp;
    Monome  *theMonome;
    float   result;

    result = 0;
    temp = poly->firstElement;
    while(temp != NULL){
        theMonome = (Monome *)(temp->info);
        result += (theMonome->coef) * pow(x, theMonome->expo);
        temp = temp->next;
    }
    return result;
}

List *drivPoly(List *poly){
    List    *drivePoly;
    Element *temp;
    Monome  *theMonome;
    Monome  *newMonome;

    drivePoly = listInit(drivePoly);

    temp = poly->firstElement;
    while(temp != NULL){
        theMonome = (Monome *)(temp->info);
        if(theMonome->expo != 0){
            newMonome = (Monome *)malloc(sizeof(Monome));
            newMonome->coef = theMonome->coef * theMonome->expo;
            newMonome->expo = theMonome->expo - 1;
            listAdd(drivePoly, (void *)newMonome);
        }
        temp = temp->next;
    }
    return drivePoly;
}