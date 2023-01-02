#ifndef ll
#define ll

typedef struct node
{
    int data;
    struct node *next;
} node;

int menu();
node *createLinkedList();
void displayLinkedList(node *);
node *accessNode(node *, int);
void nodeInsertion(node *, int);
void nodeDeletion(node *);
void headInsert(node **, int);
void headDelete(node **);
node *reverseLinkedList(node *);
void testnode(node *);

#endif



#ifndef stdio
#define stdio

#include <stdio.h>

#endif

#ifndef stdlib
#define stdlib

#include <stdlib.h>

#endif
