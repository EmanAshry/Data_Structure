#include "Queue_lib.h"

void createQueue(ST_queueInfo* info, int maxSize)
{
    info->Head_pointer = (uint8_t*)calloc(maxSize,sizeof(uint8_t));   // Create array and point to the start of it with Head_pointer
    info->Queue_pointer = info->Head_pointer;
    info->enqueue_pointer = info->Head_pointer;
    info->Size = maxSize;
}

void enqueue(ST_queueInfo *info, int data)
{
    if(info->index <= info->Size)
    {
        *(info->enqueue_pointer)= data; // enqueue data
        info->index= (info->index)+1;   //increment index
        info->enqueue_pointer = (info->enqueue_pointer)+1;    // increment queue pointer
    }
}

void dequeue(ST_queueInfo *info, int* data)
{
    if(info->index != 0)
    {
        *data = *(info->Queue_pointer);                  // dequeue data
        info->index = (info->index)-1;                    //decrement the index
        info->Queue_pointer = (info->Queue_pointer)+1;    //make stack pointer points to the last inserted element
    }
}

