// contains all functions involved with saving/loading ll

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "ll.h"

#define MAXDIGITS 10
#define COUNTER_FILE "lltemp"             /* where they are stored */
#define NEW_COUNTER_FILE COUNTER_FILE "~" /* note use of constant string concatenation */

//Logical error exists - the file where the save happens is not fully cleared.
//need to fully clear the file. Deleting file is not an option since we want to keep fp and mmap open so multiple saves can be made
//so fully clear file and then store char arr init
//pass it pointer to ll-int-string
int saveLinkedListString(char *arr)
{
    int fd;
    void *file_memory;
    int length = strlen(arr);

    /* Prepare a file large enough to hold an unsigned integer. */
    fd = open(COUNTER_FILE, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd < 0)
    {
        perror("open failed");
        exit(1);
    }

        off_t lastoffset = lseek(fd, length + 1, SEEK_SET);
        if (lastoffset < 0)
        {
            perror("lseek() failed");
        }
        else
        {
            // grows file size to 1 page
            size_t bytesWritten = write(fd, " ", 1);
        }

    /* Create the memory mapping. */

    file_memory = mmap(0, length, PROT_WRITE, MAP_SHARED, fd, 0);
    if (file_memory == MAP_FAILED)
    {
        perror("mmap failed");
        exit(2);
    }

    memcpy (file_memory, arr, length+1);

    // dont need to release inside this function, have another function to take care of it
    munmap(file_memory, length+1);
    close(fd);
    return 0;
}


//pass head and length of ll, returns pointer to char arr containing the str
//error: buffer needs to BE passed to func
void l2SConverter(node *head, char *buffer)
{
    //initialize a temp buffer which will contain the ("%d ",temp->data) value
    char tempBuff[MAXDIGITS];
    for (node *temp = head; temp != 0; temp = temp->next)
    {
        sprintf(tempBuff, "%d ", temp->data);
        strcat(buffer, tempBuff);
    }
}

/*returns length and ref calls NUMLENGTH
used to allocate exact space to buffer -> buffer[length + numlength]
*/
int llength(node *head, int *numlength)
{
    int length = 0;
    int tempNumLength = 0;
    int tempStore;
    for (node *temp = head; temp != 0; temp = temp->next)
    {
        tempStore = temp->data;
        while(tempStore > 0)
        {
            tempNumLength++;
            tempStore /= 10;
        }
        length++;
    }
    *numlength = tempNumLength;
    return length;
}