#ifndef TREE
#define TREE

    //array
    struct Noeud{
        int info;
        int ifg;
        int ifd;
    };
    typedef struct Noeud Noeud;

    //linked list
    typedef int LanyType;
    typedef struct LNoeud LNoeud;
    typedef struct LNoeud *LTree;
    struct LNoeud{
        LanyType    info;
        LTree       LN;
        LTree       RN;
    };

#endif