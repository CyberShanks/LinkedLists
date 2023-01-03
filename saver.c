// contains all functions involved with saving/loading ll

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "ll.h"

#define COUNTER_FILE "lltemp"             /* where they are stored */
#define NEW_COUNTER_FILE COUNTER_FILE "~" /* note use of constant string concatenation */

//pass it pointer to ll-int-string
int saveLinkedList(char *arr)
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

    int PageSize = (int)sysconf(_SC_PAGESIZE);
    if (PageSize < 0)
    {
        perror("sysconf() failed");
    }
    else
    {
        printf("Size of page = %d\n", PageSize);
        off_t lastoffset = lseek(fd, PageSize - 1, SEEK_SET);
        if (lastoffset < 0)
        {
            perror("lseek() failed");
        }
        else
        {
            // grows file size to 1 page
            size_t bytesWritten = write(fd, " ", 1);
        }
    }

    // this only holds an int
    // lseek(fd, FILE_LENGTH + 1, SEEK_SET);
    // write(fd, "", 1);
    // lseek(fd, 0, SEEK_SET);

    /* Create the memory mapping. */

    file_memory = mmap(0, PageSize, PROT_WRITE, MAP_SHARED, fd, 0);
    if (file_memory == MAP_FAILED)
    {
        perror("mmap failed");
        exit(2);
    }

    memcpy (file_memory, arr, PageSize);
    printf("step3 pass\n");
    /* Release the memory (unnecessary because the program exits). */
    // dont need to release inside this function, have another function to take care of it
    munmap(file_memory, PageSize);
    close(fd);
    return 0;
}
