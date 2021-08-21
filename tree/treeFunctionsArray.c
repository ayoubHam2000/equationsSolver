#include "../tools/bib.h"

//create an tree with array



void createTree(Noeud theTree[MAX]){
    int i;

    for(i = 0; i < MAX; i++){
        theTree[i].ifd = -2;
        theTree[i].ifg = -2;
        theTree[i].info = 0;
    }
}

Noeud racine(Noeud theTree[MAX], int ir){
    if(ir < MAX && ir >= 0){
        if(theTree[ir].ifg == -2){
            printf("ERROR accure in racine function\n");
            exit(0);
        }else{
            return theTree[ir];
        }
    }
}

int filsG(Noeud theTree[MAX], int ir){
    if(ir < MAX && ir >= 0){
        if(theTree[MAX].ifd == -2){
            printf("ERROR\n");
            exit(0);
        }else{
            return theTree[MAX].ifd;
        }
    }
}

int filsD(Noeud theTree[MAX], int ir){
    if(ir < MAX && ir >= 0){
        if(theTree[MAX].ifd == -2){
            printf("ERROR accure in fileD function\n");
            exit(0);
        }else{
            return theTree[MAX].ifd;
        }
    }
}

int construireTree(Noeud theNoeud, Noeud theTree[MAX], int irfd, int irfg){
    int i;

    theNoeud.ifd = irfd;
    theNoeud.ifg = irfg;

    i = 0;
    while(theTree[i].ifg != -2 && i < MAX){
        i++;
    }
    if(i < MAX){
        theTree[i] = theNoeud;
        return i;
    }else{
        printf("pleinne\n");
        return -1;
    }
}

int isEmpty(Noeud theTree[MAX], int ir){
    if(ir == -1) //related to the hauteur function
        return 1;
    if(theTree[ir].ifg == -2)
        return 1;
    return 0;
}

int isLeaf(Noeud theTree[MAX], int ir){
    if(theTree[ir].ifg == -1 && theTree[ir].ifd == -1){
        return 1;
    }
    return 0;
}

//mafhamtax
int hauteur(Noeud theTree[MAX], int ir){
    if( isEmpty(theTree, ir) ){
        return 0;
    }else{
        return 1 + ft_max
        ( 
            hauteur(theTree, filsG(theTree, ir) ),
            hauteur(theTree, filsD(theTree, ir) )
        );
    }
}

int taille(Noeud theTree[MAX], int ir){
    if( isEmpty(theTree, ir) ){
        return 0;
    }else{
        return 1 +
        taille(theTree, filsG(theTree, ir) ) +
        taille(theTree, filsD(theTree, ir) );
    }
}