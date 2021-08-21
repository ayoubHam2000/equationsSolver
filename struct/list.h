#ifndef STRUCT_GLOBAL
#define STRUCT_GLOBAL

struct Element{
    void *info;
    struct Element *next;
};
typedef struct Element Element;

struct List{
    Element *firstElement;
};
typedef struct List List;


#endif