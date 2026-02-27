#ifndef TREE_H
#define TREE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#define SLEN    20

typedef struct item
{
    char petname[SLEN];
    char petkind[SLEN];
} Item;

#define MAXITEMS    10

typedef struct tnode
{
    Item item;
    struct tnode *left;
    struct tnode *right;
} Tnode;

typedef struct tree
{
    Tnode *root;
    int size;
} Tree;

void InitializeTree(Tree * ptree);
bool TreeIsEmpty(const Tree * ptree);
bool TreeIsFull(const Tree * ptree);
int TreeItemCount(const Tree * ptree);
bool AddItem(const Item * pi, Tree * ptree);
bool InTree(const Item * pi, const Tree * ptree);
bool DeleteItem(const Item * pi, Tree * ptree);
void Traverse(const Tree * ptree, void(*pfun)(Item item));
void DeleteAll(Tree * ptree); 

#ifdef __cplusplus
}
#endif

#endif // TREE_H