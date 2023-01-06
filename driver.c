/*
AdvancedLinkedList - Linked Lists with Save/Load Function
Copyright (C) 2023 Shashank M. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "ll.h"
#include "misc.h"

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
    printf("1.New Linked List\n");
    printf("2.Display Linked List\n");
    printf("3.Access(Edit) Node\n");
    printf("4.Reverse Linked List\n");
    printf("5.Save Linked List\n");
    printf("6.Load Linked List\n");
    printf("7.License\n");
    printf("8.Exit\n>> ");
    scanf("%d", &choice);
    switch (choice)
    {
        node *head, *node;
    case 1:
        head = createLinkedList();
        printf("Linked List has been created\n");
        displayLinkedList(head);
        break;
    case 2:
        displayLinkedList(head);
        break;
    case 3:
        int nodeNum, accessChoice, insertValue, insertChoice;
        printf("Enter Node Number\n>> ");
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

        printf("Operation at Node %d\n", nodeNum);
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
            displayLinkedList(head);
            break;
        case 2:
            printf("Deleting...\n");
            if (nodeNum == 0)
            {
                headDelete(&head);
            }
            else
            {
                nodeDeletion(node);
            }
            printf("Complete!\n");
            displayLinkedList(head);
            break;
        case 3:
            break;
        default:
            printf("Please Chose a valid option");
            break;
        }
        break;
    case 4:
        head = reverseLinkedList(head);
        displayLinkedList(head);
        break;
    case 5:
        // first find length and numlength of ll
        int lengthResultArr[3];
        llLength(head, lengthResultArr);
        int length = lengthResultArr[0], numLength = lengthResultArr[1], maxNumLength = lengthResultArr[2];
        // initialize buffer using this length
        char *Buffer;
        Buffer = (char *)calloc(length + numLength + 1, sizeof(char));
        if (Buffer == NULL)
        {
            perror("calloc failed");
        }

        // pass buffer to function
        serializeLL(head, Buffer, maxNumLength);
        saveString(Buffer);
        printf("Saved!\n");
        break;
    case 6:
        printf("Loading...\n");
        head = deSerializeLL(loadString());
        displayLinkedList(head);
        break;
    case 7:
        printf("Copyright (C) 2023 Shashank M.\nThis program comes with ABSOLUTELY NO WARRANTY.\nThis is free software, and you are welcome to redistribute it under certain conditions");
        break;
    case 8:
        exit(0);
        break;

    default:
        printf("Wrong Option, Choose from given options\n");
        break;
    }
}