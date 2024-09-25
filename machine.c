#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned int PC;
    unsigned int gp;
    unsigned int fp;
    unsigned int sp;
}VMReg;

VMReg reg;


//a size for the memory(2^16 words = 32k words)
#define MEMORY_SIZE_IN_WORDS 32768

//Reads the binary object file
unsigned char* read_file(const char *fileName, long *fileSize) {

    // opens the binary object file
    FILE *file = fopen(fileName, "rb");
    //file cant be open
    if(file == NULL) {
        return NULL;
    }

    //find the size of the file
    fseek(file, 0, SEEK_END);
    //getting the file size
    *fileSize = ftell(file);
    //return the file pointer to the beginning
    rewind(file);

    unsigned char *buffer = (unsigned char *) malloc(*fileSize);
    //if the memory allocation fails
    if(buffer == NULL) {
        fclose(file);
        return NULL;
    }

    
    size_t bytes_read = fread(buffer, 1, *fileSize, file);
    //memory allocation fails
    if(bytes_read != *fileSize) {
        free(buffer);
        fclose(file);
        return NULL;
    }

    //read the header information
    unsigned int text_length = *(unsigned int*)(buffer);
    //read first 4 bytes
    unsigned int data_start_address = *(unsigned int*)(buffer + 4);
    //read from 4-7
    unsigned int stack_bottom_address = *(unsigned int*)(buffer + 8);
    //read from 8-11

    //initialize the registers
    reg.PC = 0;
    reg.gp = data_start_address;
    reg.fp =stack_bottom_address;
    reg.sp = text_start_address;

    //get the text section of the bof file
    for(int i =0;I<text_length;i++){
        
    }


    fclose(file);
    //returns the contents of the file
    return buffer;

}



    



/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
