/*
AdvancedLinkedList - Linked Lists with Save/Load Function
Copyright (C) 2023 Shashank M. 
*/

#ifndef misc
#define misc


    #include "ll.h"
    
    /* storage filename */
    #define FILE_NAME "lltemp" 

    int saveString(char *);
    void serializeLL(node *, char *, int);
    char *loadString();
    node *deSerializeLL(char *);

#endif