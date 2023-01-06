/*
AdvancedLinkedList - Linked Lists with Save/Load Function
Copyright (C) 2023 Shashank M. 
*/
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "ll.h"
#include "misc.h"

//copies a string to FILE_NAME (defined in misc.h)
int saveString(char *dataString)
{
    int fd;
    void *file_memory;
    int length = strlen(dataString);

    //open file
    fd = open(FILE_NAME, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd < 0)
    {
        perror("open failed");
        exit(1);
    }

    //grow filesize to length+1
    off_t lastoffset = lseek(fd, length + 1, SEEK_SET);
    if (lastoffset < 0)
    {
        perror("lseek() failed");
    }
    else
    {
        // grows file size
        size_t bytesWritten = write(fd, " ", 1);
    }

    //mapping memory
    file_memory = mmap(0, length + 1, PROT_WRITE, MAP_SHARED, fd, 0);
    if (file_memory == MAP_FAILED)
    {
        perror("mmap failed");
        exit(2);
    }

    //can close fd, mmap has created a special reference to the file
    close(fd);

    //copy string into file
    memcpy(file_memory, dataString, length + 1);

    //release the memory
    munmap(file_memory, length + 1);
    return 0;
}

//Serializes LL data to String as "%d %d ..."
void serializeLL(node *head, char *buffer, int maxDigits)
{
    // initialize a temp buffer which will contain the ("%d ",temp->data) value
    char *tempBuff;
    tempBuff = (char *)calloc(maxDigits, sizeof(char));
    for (node *temp = head; temp != 0; temp = temp->next)
    {
        sprintf(tempBuff, "%d ", temp->data);
        //concatenate to buffer
        strcat(buffer, tempBuff);
    }
}

//read file and return file_info as string
char *loadString()
{
    int fd;
    void *file_memory;
    char *llString;
    struct stat sb;

    //open the file
    fd = open(FILE_NAME, O_RDONLY, S_IRUSR);
    if (fd < 0)
    {
        printf("NO SAVES Found");
        return NULL;
    }

    //get filesize
    if (fstat(fd, &sb) == -1)
    {
        perror("fstat error");
    }
    int totalLength = sb.st_size;

    //use filesize to allocate sufficient sized memory
    llString = (char *)calloc(totalLength, sizeof(char));

    //Map Memory
    file_memory = mmap(0, totalLength, PROT_READ, MAP_SHARED, fd, 0);
    close(fd);

    //Copy from mapped memory into buffer
    memcpy(llString, file_memory, totalLength);

    //release memory
    munmap(file_memory, totalLength);
    return llString;
}

// Deserialize ll from String
node *deSerializeLL(char *dataString)
{
    node *head = 0, *newnode, *temp;
    int tempNum;
    char *token;

    //breaks down string using delimiter into tokens, token takes values serially
    for (token = strtok(dataString, " "); token != NULL; token = strtok(NULL, " "))
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->data = atoi(token);
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
    return head;
}