
#include "List_lib.h"

char createList(ST_list *list)
{
    list->Head_pointer = (ST_node*)malloc(sizeof(ST_node));
}

/*Insert at the front of the list*/
void insertFront(ST_node **listHead, uint8_t data)
{
    ST_node *new_node = NULL;

    new_node = (ST_node*)malloc(sizeof(ST_node));

    if (new_node == NULL)
    {
        printf("Out of memory");
        return;
    }

    new_node->data = data;               //Setting the value of the node
    new_node->Next_pointer = *listHead; //Pointing the new node where head is currently pointing to

    *listHead = new_node;                  //Pointing head to new element
}

/*find the node with its value and insert the new one after it*/
void insertToList(ST_node *listHead, uint8_t position_data, uint8_t data)
{
    ST_node *new_node = NULL;
    ST_node *tmp = listHead;

    while(tmp)
    {
      if(tmp->data == position_data)
      {
        new_node = (ST_node*)malloc(sizeof(ST_node));

        if (new_node == NULL)
        {
          printf("Out of memory");
          return;
        }

        new_node->data = data;
        new_node->Next_pointer = tmp->Next_pointer;
        tmp->Next_pointer = new_node;

        return;
      }

      tmp = tmp->Next_pointer;
    }
}

/*find the node to be deleted with its value then free it and link the surrounding nodes*/
void deleteFromList(ST_node *listHead, uint8_t position_data)
{
    ST_node *deleted_node = listHead;
    ST_node *tmp = listHead;

    if(listHead->data == position_data)
    {
        listHead= listHead->Next_pointer;
        return;
    }
    else
    {
        /*start from second element*/
        deleted_node = listHead->Next_pointer;
        while(deleted_node)
        {
            if(deleted_node->data == position_data)
            {
                tmp->Next_pointer = deleted_node->Next_pointer;

                free(deleted_node);

                return;
            }
            deleted_node = deleted_node->Next_pointer;
            tmp = tmp->Next_pointer;
        }
    }
}

ST_node* searchIntoList(ST_node *listHead, int data)
{
    ST_node *tmp = listHead;

    while(tmp)
    {
      if(tmp->data == data)
      {
        return tmp;
      }

      tmp = tmp->Next_pointer;
    }
    return NULL;
}

