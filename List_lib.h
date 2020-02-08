#include "std_types.h"
#include <stdlib.h>
#include <stdio.h>

/*user defined types*/
typedef struct st_node{
    ST_node *Next_pointer;
    uint8_t data;
}ST_node;

typedef struct st_list{
    ST_node *Head_pointer;
    uint8_t Nodes_counter;
}ST_list;

/*variables*/
ST_list List_1;

/*functions prototypes*/
extern char createList(ST_list *List);
extern void insertFront(ST_node **listHead, uint8_t data);
extern void insertToList(ST_node *listHead, uint8_t position_data, uint8_t data);
extern void deleteFromList(ST_node *listHead, uint8_t position_data);
extern ST_node* searchIntoList(ST_node *listHead, int data);


