// contains all functions involved with saving/loading ll
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "ll.h"
#include "misc.h"


// pass it pointer to ll-int-string
int saveString(char *arr)
{
    int fd;
    void *file_memory;
    int length = strlen(arr);

    /* Prepare a file large enough to hold an unsigned integer. */
    fd = open(FILE_NAME, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
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

    file_memory = mmap(0, length+1, PROT_WRITE, MAP_SHARED, fd, 0);
    if (file_memory == MAP_FAILED)
    {
        perror("mmap failed");
        exit(2);
    }

    memcpy(file_memory, arr, length + 1);

    munmap(file_memory, length + 1);
    close(fd);
    return 0;
}

// pass head and length of ll, returns pointer to char arr containing the str
void l2SConverter(node *head, char *buffer, int maxDigits)
{
    // initialize a temp buffer which will contain the ("%d ",temp->data) value
    char *tempBuff;
    tempBuff = (char *)calloc(maxDigits, sizeof(char));
    for (node *temp = head; temp != 0; temp = temp->next)
    {
        sprintf(tempBuff, "%d ", temp->data);
        strcat(buffer, tempBuff);
    }
}
