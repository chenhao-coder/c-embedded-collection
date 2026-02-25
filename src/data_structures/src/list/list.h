#ifndef LIST_H
#define LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>    /* C99 特性 */

#define TSIZE       45

struct film
{
    char title[TSIZE];
    int rating;
};

/* 一般类型定义 */
typedef struct film Item;

typedef struct node
{
    Item item;
    struct node * next;
} Node;

typedef Node * List;

/* 函数原型 */

void InitializeList(List * plist);
bool ListIsEmpty(const List * plist);
bool ListIsFull(const List * plist);
unsigned int ListItemCount(const List * plist);
bool AddItem(Item item, List * plist);
void Traverse(const List * plist, void(*pfun)(Item item));
void EmptyTheList(List * plist);

#ifdef __cplusplus
}
#endif

#endif // LIST_H