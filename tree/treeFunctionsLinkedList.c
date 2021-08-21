#include "../tools/bib.h"

LTree createLTree(){
    return NULL;
}

LNoeud Lracine(LTree theTree){
    if(theTree == NULL){
        printf("the tree is empty\n");
        exit(0);
    }else{
        return *theTree;
    }
}

LTree LfilsD(LTree theTree){
    if(theTree == NULL){
        printf("the tree is empty\n");
        exit(0);
    }else{
        return theTree->RN;
    }
}

LTree LfilsG(LTree theTree){
    if(theTree == NULL){
        printf("the tree is empty\n");
        exit(0);
    }else{
        return theTree->LN;
    }
}

int LisEmpty(LTree theTree){
    return theTree == NULL;
}

LanyType Lcontenue(LTree theTree){
    if(theTree == NULL){
        printf("the tree is empty\n");
        exit(0);
    }
    return theTree->info;
}

LTree LbuildTree(LanyType theInfo, LTree LN, LTree RN){
    LNoeud *newNoeud; //LTree is LNoeud *

    newNoeud = (LNoeud *)malloc(sizeof(LNoeud));
    newNoeud->info = theInfo;
    newNoeud->LN = LN;
    newNoeud->RN = RN;
    return newNoeud;
}

int LHauteur(LTree theTree){
    if(theTree == NULL){
        return 0;
    }else{
        return 1 + ft_max
        ( 
            LHauteur(LfilsD(theTree)), 
            LHauteur(LfilsG(theTree))
        );
    }
}

int LLongeur(LTree theTree){
    if(theTree == NULL){
        return 0;
    }else{
        return 1 + LLongeur( LfilsD(theTree) ) + LLongeur( LfilsG(theTree) );
    }
}

/*********************************/
//+++++ parcoure longeur
//there is three type prefixe(p, g, d), infixe(g, p, d), postfixe(g, d, p);

void prefixe(LTree theTree){
    if(theTree != NULL){
        printf("%d - ", theTree->info);
        prefixe(theTree->LN);
        prefixe(theTree->RN);
    }
}

void infixe(LTree theTree){
    if(theTree != NULL){
        prefixe(theTree->LN);
        printf("%d - ", theTree->info);
        prefixe(theTree->RN);
    }
}

void postfixe(LTree theTree){
    if(theTree != NULL){
        prefixe(theTree->LN);
        prefixe(theTree->RN);
        printf("%d - ", theTree->info);
    }
}

//+++++parcours en largeur


/*********************************/
//search tree

//version recursive
int r_existInfo(LTree theTree, LanyType info){
    if(theTree == NULL){
        return 0;
    }else if(info == theTree->info){
        return 1;
    }else if(info < theTree->info){
        return r_existInfo(theTree->LN, info);
    }else{
        return r_existInfo(theTree->RN, info);
    }
}

//version iterative
int i_existEl(LTree theTree, LanyType info){
    LTree temp;

    temp = theTree;
    while(temp != NULL){
        if(temp->info == info){
            return 1;
        }else if(info < temp->info){
            temp = theTree->LN;
        }else{
            temp = theTree->RN;
        }
    }
    return 0;
}

//search for nead
LNoeud *r_existEl(LTree theTree, LanyType info){
    if(theTree == NULL){
        return NULL;
    }else if(info == theTree->info){
        return theTree;
    }else if(info < theTree->info){
        return r_existEl(theTree->LN, info);
    }else{
        return r_existEl(theTree->RN, info);
    }
}

//min Noeud r
LNoeud *r_minTree(LTree theTree){
    if(theTree == NULL){
        return NULL;
    }else if(theTree->LN == NULL){
        return theTree;
    }else{
        return r_minTree(theTree->LN);
    }
}

//min Noeud i
LNoeud *i_minTree(LTree thetree){
    
    while(thetree != NULL){
        if(thetree->LN == NULL){
            return thetree;
        }else{
            thetree = thetree->LN;
        }
    }
    return NULL;
}

//max Noeud r
LTree r_maxTree(LTree theTree){
    if(theTree == NULL){
        return NULL;
    }else if (theTree->RN == NULL){
        return theTree;
    }else{
        return r_maxTree(theTree);
    }
}

//inserer
LTree i_inserer(LTree theTree, LanyType info){
    LTree   temp;
    LNoeud  *newElement;

    newElement = (LNoeud *)malloc(sizeof(LNoeud));
    newElement->info = info;
    newElement->LN = NULL;
    newElement->RN = NULL;

    temp = theTree;
    if(theTree == NULL){
        theTree = newElement;
        return theTree;
    }
    while(temp != NULL){
        if(info <= temp->info){
            if(temp->LN == NULL){
                temp->LN = newElement;
                return theTree;
            }else{
                temp = temp->LN;
            }
        }else{
            if(temp->RN == NULL){
                temp->RN = newElement;
                return theTree;
            }else{
                temp = temp->RN;
            }
        }
    }
}

//suppression
//La suppression d’un noeud dans un ABR nécessite 
//la connaissance de l’adresse de son père

LNoeud *Lparent(LTree theTree, LNoeud *target){
    LNoeud *temp;

    if(theTree == target){
        return NULL;
    }
    temp = theTree;
    while((temp->LN != target) && (temp->RN != target)){
        if(target->info <= temp->info){
            temp = temp->LN;
        }else{
            temp = temp->RN;
        }
    }
    return temp;

}

/*
3eme cas  Nd a deux fils
Sa valeur sera remplacer par celle du noeud qui a
la plus grande valeur du sous arbre gauche (ou la plus petite valeur du sousarbre
droit) et de supprimer le noeud associé dans le sous arbre gauche (ou
droit) .
*/

LNoeud *LdeleteNoeud(LTree theTree, LNoeud *target){
    LNoeud *temp;
    LNoeud *parent;

    parent = Lparent(theTree, target);
    //if target has no parent
    if(parent == NULL){
        if(target->LN == NULL && target->RN == NULL){
            free(target);
            return NULL;
        }
        if(target->LN != NULL){
            target->info = target->LN->info;
            free(target->LN);
            target->LN = NULL;
            return theTree;
        }else{
            target->info = target->RN->info;
            free(target->RN);
            target->RN = NULL;
            return theTree;
        }
    }
    //1er cas un feuille
    else if(target->LN == NULL && target->RN == NULL){
        if(parent->LN == target){
            parent->LN = NULL;
        }else{
            parent->RN = NULL;
        }
        free(theTree);
        return theTree;
    }
    //2eme cas Nd a un seul fils
    else if(target->LN == NULL || target->RN == NULL){
        if(target->LN != NULL){
            if(parent->LN == target){
                parent->LN = target->LN;
            }else{
                parent->RN = target->LN;
            }
        }else{
            if(parent->LN == target){
                parent->LN = target->RN;
            }else{
                parent->RN = target->RN;
            }
        }
        free(target);
        return theTree;
    }
    //3eme cas  Nd a deux fils
    else{
        temp = r_maxTree(target->LN);
        target->info = temp->info;
        parent = Lparent(theTree, temp);
        //parent can not be the target because we treated this cases above
        //temp is max of the target left tree so he has no Right child.
        //temp is the right child of his parent.
        parent->RN = temp->LN;
        free(temp);
        return theTree;
    }
}

//AVL left rotation
//Dans la rotation gauche, un noeud devient le fils gauche du noeud qui était son
//fils droit.
LTree rotationL(LTree theTree){
    LNoeud *rightChild;

    rightChild = theTree->RN;
    theTree->RN = rightChild->LN;
    rightChild->LN = theTree;
    return rightChild;
}
//Dans la rotation droite, un noeud devient le fils droit du noeud qui était son fils
//gauche.

LTree rotationR(LTree theTree){
    LNoeud *leftChild;

    leftChild = theTree->LN;
    theTree->LN = leftChild->RN;
    leftChild->RN = theTree;
    return leftChild;

}

/*
Le facteur d'équilibrage d'un noeud est la différence entre la hauteur de son
sous-arbre droit et celle de son sous-arbre gauche.
feq(Nd) = h(filsD(Nd) - h(filsG(Nd)
Chaque fois qu'un noeud est inséré ou supprimé d'un arbre AVL, le facteur
d'équilibrage de chaque noeud le long du chemin depuis la racine jusqu'au noeud
inséré (ou supprimé) doit être recalculé.

Types de rotations :
1-Une rotation simple droite est utilisée quand un noeud a un facteur d'équilibrage
inférieur à -1 et que son fils gauche a un facteur d'équilibrage de -1.

2-Une rotation double droite est utilisée quand un noeud a un facteur
d'équilibrage inférieur à -1 et que son fils gauche a un facteur d'équilibrage de
+1. La double rotation droite est une rotation simple gauche du sous-arbre
gauche, suivi d'une rotation simple droite du noeud déséquilibré. Cette opération
est aussi appelée parfois une rotation gauche-droite.

3-Une rotation simple gauche est utilisée quand un noeud a un facteur
d'équilibrage supérieur à +1 et que son fils droit a un facteur d'équilibrage de +1

4-Une rotation double gauche est utilisée quand un noeud a un facteur
d'équilibrage supérieur à +1 et que son fils droite a un facteur d'équilibrage de
-1. La double rotation gauche est une rotation simple droite du sous-arbre droit,
suivi d'une rotation simple gauche du noeud déséquilibré. Cette opération est
aussi appelée parfois une rotation droite-gauche.
*/

//equilibrer function
LTree treeBalancer(LTree theTree, LNoeud *child){
    int     lh;
    int     rh;
    int     dh;
    LNoeud *parent;

    if(child == NULL){
        return theTree;
    }else{
        lh = LHauteur(LfilsG(child));
        rh = LHauteur(LfilsD(child));
        if(rh - lh == 2){ // rh - lh > 1 ?? Rotation vers la gauche
            dh = LHauteur( LfilsD(LfilsD(child)) ) - LHauteur( LfilsG(LfilsD(child)) );
            if(dh < 0){// Rotation driote-gauche
                child->RN = rotationR(child->RN);
            }
            child = rotationL(child);
        }else if(rh -lh == -2){//Rotation vers la droite
            dh = LHauteur( LfilsD(LfilsG(child)) ) - LHauteur( LfilsG(LfilsG(child)) );
            if(dh > 0){// Rotation gauche-droite
                child->LN = rotationL(child->LN);
            }
            child = rotationR(child);
        }
    }
    parent = Lparent(theTree, child);
    if(parent == NULL){
        return theTree;
    }else{
        return treeBalancer(theTree, parent);
    }
}
