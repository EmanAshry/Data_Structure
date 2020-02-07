#include "stack_lib.h"

void createStack(ST_stackInfo *info, int size)
{
    info->Head_pointer = (uint8_t*)calloc(size,sizeof(uint8_t));   // Create array and point to the start of it with Head_pointer
    info->Stack_pointer = info->Head_pointer;
    info->Size = size;
}
void push(ST_stackInfo *info, int data)
{
    if(info->index <= info->Size)
    {
        *(info->Stack_pointer)= data; // push data
        info->index= (info->index)+1;   //increment index
        info->Stack_pointer = (info->Stack_pointer)+1;    // increment stack pointer
    }
}
void pop(ST_stackInfo *info, int* data)
{
    if(info->index != 0)
    {
        info->Stack_pointer = (info->Stack_pointer)-1;    //make stack pointer points to the last inserted element
        *data = *(info->Stack_pointer);                  // pop data
        info->index = (info->index)-1;                    //decrement the index
    }
}

unsigned char checkForBalancedParantheses(char* expression)
{
    uint8_t size=0;
    uint8_t brackets_counter=0;
    uint8_t poped_data=0;
    Loop_inc =0;

    free(Stack_2.Head_pointer);

    size = strlen(expression);
    createStack(&Stack_2,size);

    while(expression[Loop_inc] != NULL)
    {
        if((expression[Loop_inc]=='(')||(expression[Loop_inc]=='[')||(expression[Loop_inc]=='{'))
            {
                brackets_counter++;
                printf("%d \n", brackets_counter);
            }

        push(&Stack_2,expression[Loop_inc]);
        Loop_inc++;
    }

    while(Loop_inc)
    {
        pop(&Stack_2,&poped_data);
        printf("%c \n",poped_data);
        if((poped_data == ')')||(poped_data == ']')||(poped_data == '}'))
           {
               brackets_counter -- ;
               printf("%d \n",brackets_counter);
           }

        Loop_inc--;
    }

    if(brackets_counter==0)
    {
        return 'T';
    }
    else
    {
        return 'F';
    }
}
