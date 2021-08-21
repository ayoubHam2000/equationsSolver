#ifndef FUNCTIONS
#define FUNCTIONS

	// +----> polynomes/operations.c

	List *buildPoly(char *thePoly);
	void displayPoly(List *poly);
	float calculPoly(List *poly, float x);
	List *drivPoly(List *poly);


	// +----> polynomes/polySolver.c

	float solvePoly(List *poly, float init, int max);
	float dichotomie(List *poly, float a, float b, float precision);


	// +----> list/listFunctions.c

	List *listInit(List *theList);
	int listLen(List *theList);
	Element *listGetAtPos(List *theList, int pos);
	void listInserte(List *theList, void *info, int pos);
	void listDeleteAt(List *theList, int pos);
	void listAdd(List *theList, void *info);
	void listPush(List *theList, void *info);
	void listPop(List *theList);
	void listShift(List *theList);


	// +----> healpers/atoi.c

	void	filter(char *str, int *bigin, int *fin);
	int		ft_atoi(char *str);


	// +----> healpers/casting.c

	int LIST_TO_INT(List *theList, int pos);


	// +----> healpers/ft_split.c

	int		is_there_char_charset(char str, char *charset);
	char	*cpy(char *dest, char *src, int n);
	char	**words(char *str, char *charset);
	void	characters(char **tab, char *p, char *charset);
	char	**ft_split(char *str, char *charset);


	// +----> healpers/functions.c

	void    newERROR(char *message);
	int		str_len(char *str);
	float	ft_abs(float a);
	int ft_max(int a, int b);


	// +----> tree/treeFunctionsArray.c

	void createTree(Noeud theTree[MAX]);
	Noeud racine(Noeud theTree[MAX], int ir);
	int filsG(Noeud theTree[MAX], int ir);
	int filsD(Noeud theTree[MAX], int ir);
	int construireTree(Noeud theNoeud, Noeud theTree[MAX], int irfd, int irfg);
	int isEmpty(Noeud theTree[MAX], int ir);
	int isLeaf(Noeud theTree[MAX], int ir);
	int hauteur(Noeud theTree[MAX], int ir);
	int taille(Noeud theTree[MAX], int ir);


	// +----> tree/treeFunctionsLinkedList.c

	LTree createLTree();
	LNoeud Lracine(LTree theTree);
	LTree LfilsD(LTree theTree);
	LTree LfilsG(LTree theTree);
	int LisEmpty(LTree theTree);
	LanyType Lcontenue(LTree theTree);
	LTree LbuildTree(LanyType theInfo, LTree LN, LTree RN);
	int LHauteur(LTree theTree);
	int LLongeur(LTree theTree);
	LNoeud *LdeleteNoeud(LTree theTree, LNoeud *target);
	LTree rotationL(LTree theTree);
	LTree rotationR(LTree theTree);
	LTree treeBalancer(LTree theTree, LNoeud *child);




#endif