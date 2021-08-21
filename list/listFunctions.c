#include "../tools/bib.h"

List *listInit(List *theList){
    theList = (List *)malloc(sizeof(List));
    theList->firstElement = NULL;
    return theList;
}

int listLen(List *theList){
    int i;
    Element *temp;

    i = 0;
    temp = theList->firstElement;
    while(temp != NULL){
        temp = temp->next;
        i++;
    }
    return i;
}

Element *listGetAtPos(List *theList, int pos){
    Element *theElement;

    if(pos >= 0 && pos < listLen(theList)){
        theElement = theList->firstElement;
        while(pos > 0){
            theElement = theElement->next;
            pos--;
        }

    }else{
        newERROR("list out of index");
    }

    return theElement;
}

void listInserte(List *theList, void *info, int pos){
    if(pos >= 0 && pos <= listLen(theList)){
        Element *newElement;
        Element *previousElement;

        newElement = (Element *)malloc(sizeof(Element));
        newElement->info = info;
        newElement->next = NULL;

        if(pos == 0){
            newElement->next = theList->firstElement;
            theList->firstElement = newElement;
        }else{
            previousElement = listGetAtPos(theList, pos - 1);
            newElement->next = previousElement->next;
            previousElement->next = newElement;
        }

    }else{
        newERROR("list out of index");
    }
}

void listDeleteAt(List *theList, int pos){
    Element *temp;
    Element *previousElement;

    if(pos >= 0 && pos < listLen(theList)){
        if(pos == 0){
            temp = theList->firstElement->next;
            free(theList->firstElement);
            theList->firstElement = temp;
        }else{
            previousElement = listGetAtPos(theList, pos - 1);
            temp = previousElement->next;
            previousElement->next = temp->next;
            free(temp);
        }
    }else{
        newERROR("index out of range");
    }
}

 /********************************************/
void listAdd(List *theList, void *info){
    listInserte(theList, info, listLen(theList));
}

void listPush(List *theList, void *info){
    listInserte(theList, info, 0);
}

void listPop(List *theList){
    listDeleteAt(theList, listLen(theList) - 1);
}

void listShift(List *theList){
    listDeleteAt(theList, 0);
}