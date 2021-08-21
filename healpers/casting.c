#include "../tools/bib.h"

int LIST_TO_INT(List *theList, int pos){
    void *p = listGetAtPos(theList, pos)->info;
    return *((int *)p);
}