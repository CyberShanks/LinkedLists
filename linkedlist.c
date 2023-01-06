/*
AdvancedLinkedList - Linked Lists with Save/Load Function
Copyright (C) 2023 Shashank M. 
*/

#include <stdlib.h>
#include "ll.h"

// creates a linked list, returns head ptr
node *createLinkedList()
{
    node *head, *newnode, *temp;
    int value;
    head = 0;
    printf("Enter a 0 when you want to stop creating nodes\n");
    for (int num = 0; temp->data != 0; num++)
    {
        printf("Value for Node %d >> ", num);
        scanf("%d", &value);
        if (value != 0)
        {
            newnode = (node *)malloc(sizeof(node));
            newnode->data = value;
            newnode->next = 0;
            if (head == 0)
            {
                head = temp = newnode;
            }
            else
            {
                temp->next = newnode;
                temp = newnode;
            }
        }
        else
        {
            return head;
        }
    }
}

// traverses ll given head node
void displayLinkedList(node *head)
{
    node *temp = head;
    for (; temp->next != 0; temp = temp->next)
    {
        printf("|%d|->", temp->data);
    }
    printf("|%d|", temp->data);
}

// returns a pointer to the nodenumber
node *accessNode(node *head, int nodeNumber)
{
    node *temp = head;
    for (int i = 0; i < nodeNumber; i++)
    {
        temp = temp->next;
    }
    return temp;
}

// inserts a node INFRONT of node location provided
void nodeInsertion(node *currentNode, int insertValue)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = insertValue;
    newnode->next = currentNode->next;
    currentNode->next = newnode;
}

// deletes currentNode using prevNode
void nodeDeletion(node *prevNode)
{
    node *nextnode = prevNode->next;
    prevNode->next = nextnode->next;
    free(nextnode);
}

// deletes the head node
void headDelete(node **head)
{
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// changes head of the ll
void headInsert(node **head, int insertValue)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = insertValue;
    newnode->next = *head;
    *head = newnode;
}

/*Traverse current ll, simultaneously creating another ll with reverse link.
Returns a new ll.
*/
node *reverseLinkedList(node *currentHead)
{
    node *temp, *newnode, *prevNode, *newPrevNode;
    prevNode = temp = currentHead;
    newPrevNode = 0;
    while (temp)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->data = temp->data;
        if (temp == currentHead)
        {
            newnode->next = newPrevNode;
        }
        else
        {
            newnode->next = newPrevNode;
            if (prevNode != currentHead)
            {
                free(prevNode);
            }
            prevNode = temp;
        }
        newPrevNode = newnode;

        if (temp->next != 0)
        {
            temp = temp->next;
        }
        else
        {
            free(currentHead);
            return newnode;
        }
    }
}

// testfunction to test a node
void testnode(node *node)
{
    printf(">>|%d|%p|\n%p\n\n", node->data, node->next, node);
}

/*call with head and lengthArr
lengthArr = [length, totalNumLength, maxNumLength]
*/
void llLength(node *head, int *lengthArr)
{
    int length = 0;
    int totalNumLength = 0;
    int tempStore;
    int maxNumLength = 1;
    for (node *temp = head; temp != 0; temp = temp->next)
    {
        tempStore = temp->data;
        int numLength = 0;
        while (tempStore > 0)
        {
            numLength++;
            tempStore /= 10;
        }
        length++;
        if (numLength > maxNumLength)
        {
            maxNumLength = numLength;
        }
        totalNumLength += numLength;
    }
    lengthArr[0] = length;
    lengthArr[1] = totalNumLength;
    lengthArr[2] = maxNumLength;
}