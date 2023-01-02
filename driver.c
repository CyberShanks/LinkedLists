#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main(int argc, char const *argv[])
{
    while (1)
    {
        menu();
    }
    return 0;
}

int menu()
{
    int choice;
    printf("\n----------\n");
    printf("Choose Action\n");
    printf("1.Initialize Linked List\n");
    printf("2.Display Linked List\n");
    printf("3.Access Value at a Position\n");
    printf("4.Reverse Linked List?\n");
    printf(".Save Current Linked List\n");
    printf("8.Exit\n>> ");
    scanf("%d", &choice);
    switch (choice)
    {
        node *head, *node;
        int nodeNum, accessChoice, insertValue, insertChoice;
    case 1:
        head = createLinkedList();
        printf("Linked List has been created\n");
        displayLinkedList(head);
        break;
    case 2:
        displayLinkedList(head);
        break;
    case 3:
        printf("Enter Node Number to be accessed\n>> ");
        scanf("%d", &nodeNum);
        // write exception for when nodenum is 0
        node = accessNode(head, nodeNum - 1);
        if (nodeNum == 0)
        {
            printf("Value at %d = |%d|\n", nodeNum, node->data);
        }
        else
        {
            printf("Value at %d = |%d|\n", nodeNum, (node->next)->data);
        }

        printf("Which Operation do you want to perform at this Node\n");
        printf("1.Insertion\n");
        printf("2.Deletion\n");
        printf("3.Nothing\n>> ");
        scanf("%d", &accessChoice);
        switch (accessChoice)
        {
        case 1:
            // ask if we insert before or after node;
            printf("Value to insert\n>> ");
            scanf("%d", &insertValue);
            printf("Do you want to insert before or after the node?\n");
            printf("1.Before\n");
            printf("2.After\n>> ");
            scanf("%d", &insertChoice);
            if (insertChoice == 1)
            {
                if (nodeNum == 0)
                {
                    headInsert(&head, insertValue);
                }
                else
                {
                    nodeInsertion(node, insertValue);
                }
            }
            else if (insertChoice == 2)
            {
                if (nodeNum == 0)
                {
                    nodeInsertion(node, insertValue);
                }
                else
                {
                    nodeInsertion(node->next, insertValue);
                }
            }
            printf("Done!\n");
            break;
        case 2:
            printf("Deleting...\n");
            if (nodeNum == 0){
                headDelete(&head);
            }
            else{
                nodeDeletion(node);
            }
            printf("Complete!\n");
            break;
        default:
            break;
        }
        break;
    case 4:
        head = reverseLinkedList(head);
        break;
    case 5:
        // reverseLinkedList();
        break;
    case 7:
        // probably use message queue to store the linked list
        // saveLinkedList();
        break;
    case 8:
        exit(0);
        break;

    default:
        printf("Wrong Option, Choose from given options\n");
        break;
    }
}