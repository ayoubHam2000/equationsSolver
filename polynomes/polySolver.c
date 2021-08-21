#include "../tools/bib.h"

float solvePoly(List *poly, float init, int max){
    List    *dirivePoly;
    float   x1;
    float   x2;
    int     i;

    dirivePoly = drivPoly(poly);

    x1 = init;
    i = 0;
    while(i < max){
        x2 = x1 - calculPoly(poly, x1)/calculPoly(dirivePoly, x1);
        x1 = x2;
        i++;
    }
}

float dichotomie(List *poly, float a, float b, float precision){
    int c;

    if( calculPoly(poly, a)*calculPoly(poly, b) < 0){
        c = (a + b) / 2;
        while( ft_abs (calculPoly(poly, c) ) > precision ){
            if( calculPoly(poly, a) * calculPoly(poly, c) < 0 ){
                b = c;
            }else{
                a = c;
            }
            c = (a + b) / 2;
        }
        return c;
    }else{
        printf("pas de solution a cette intervale \n");
        return -1;
    }
}