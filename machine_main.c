//
// Created by Wilson Vu on 9/20/24.
//
// FILE* fopen(const char *file_name, const char *access_mode);
#include <stdio.h>
#include <string.h>
#include machine.c

int main(int argc, char *argv[]) {

    int pFlag = 0;
    const char *filename = NULL;
    unsigned char *memory = NULL;
    long fileSize;

    for(int i = 1; i < argc; i++) {
        //printf("%s\n", argv[i]);
        if(strcmp(argv[i], "-p") == 0) {
            pFlag = 1;
        }
        else{
            filename = argv[i];
        }
            
    }

    printf("flag is %d\n", pFlag);

    //load information
    unsigned char* VM_Info = read_file(fileName, &memory, &fileSize);

    //if pFlag is true print out the instruction. (Result would ble vm_test.lst for example)
    if(pFlag == 1) {

        print_file(VM_Info, &memory, &fileSize);

    }

    //else execute the program and the result should be vm_test0.out)
    else {



    }

    return 0;
}



