
#include <stdlib.h>
#include "std_types.h"

/* User defined types*/
typedef struct st_stackInfo{
    uint8_t *Head_pointer;
    uint8_t *Stack_pointer;
    uint8_t index;
    uint8_t Size;
}ST_stackInfo;

/* Variables*/
ST_stackInfo Stack_1;
ST_stackInfo Stack_2;

static uint8_t Loop_inc;

/*Extern variables*/
extern ST_stackInfo Stack_1;
extern ST_stackInfo Stack_2;

/*unctions prototypes*/
extern void createStack(ST_stackInfo *info, int size);
extern void push(ST_stackInfo *info, int data);
extern void pop(ST_stackInfo *info, int* data);
extern unsigned char checkForBalancedParantheses(char* expression);
