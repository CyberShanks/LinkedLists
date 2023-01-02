#include <stdio.h>
#include <stdlib.h>

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

//deletes the head node
void headDelete(node **head){
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



// reverses linked list and returns head
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

//prints out all info about the node it is called with
void testnode(node *node)
{
    printf(">>|%d|%d|\n%d\n\n", node->data, node->next, node);
}