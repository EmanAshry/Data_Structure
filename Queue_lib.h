

#include <stdlib.h>
#include "std_types.h"

/* User defined types*/
typedef struct st_queueInfo{
    uint8_t *Head_pointer;
    uint8_t *Queue_pointer;
    uint8_t *enqueue_pointer;
    uint8_t index;
    uint8_t Size;
}ST_queueInfo;

/* Variables*/
ST_queueInfo Queue_1;
ST_queueInfo Queue_2;

static uint8_t Loop_inc;

/*Extern variables*/
extern ST_queueInfo Queue_1;
extern ST_queueInfo Queue_2;

/*unctions prototypes*/
extern void createQueue(ST_queueInfo* info, int maxSize);
extern void enqueue(ST_queueInfo *info, int data);
extern void dequeue(ST_queueInfo *info, int* data);

