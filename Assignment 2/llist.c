/*
-------------------------------------
File:    llist.c
Project: stack_queue
file description
-------------------------------------
Author:  Heider Ali
ID:      9999999999
Email:   heali@wlu.ca
Version  2020-10-29
-------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "llist.h"

//------ NODE --------
Node_t* nodeCreate(ItemType value)
{
    Node_t* node = malloc(sizeof(Node_t));
    node->data = value;
    node->next = NULL;
    return node;
}

void nodePrint(Node_t node)
{
   char frmt[10];  // dynamically craft the format specifier
   sprintf(frmt,"[%s]%%s", ITEMTYPE_FORMAT_SPEC);
   printf(frmt, node.data, node.next ? "-->" : "--|");
}


//----- LINKED LIST -----
LinkedList_t llCreate()
{
   Node_t* dummy = nodeCreate(ITEMTYPE_NONE);
   LinkedList_t list = {dummy, dummy};
   return list;
}

void llDestroy(LinkedList_t* list)
{
   llDelete(list);
   free(list->head);
   list->head = list->tail = NULL;
}

void llPrint(const LinkedList_t list)
{
   Node_t* cur = list.head->next;
   while (cur != NULL) {
       nodePrint(*cur);
       cur = cur->next;
   }
   printf("\n\n");
}

bool llIsEmpty(const LinkedList_t list)
{
   return list.head->next == NULL;
}

void llDelete(LinkedList_t* list)
{
   while (!llIsEmpty(*list)) {
      Node_t* cur = list->head->next;
      list->head->next = cur->next;
      free(cur);
   }
   list->tail = list->head;
}


int llLength(const LinkedList_t list)
{
   Node_t* cur = list.head->next;
   int len = 0;
   while (cur != NULL) {
      len++;
      cur = cur->next;
   }
   return len;
}

void llLinkAfter(LinkedList_t* list, Node_t* cursor, Node_t* newNode)
{
   newNode->next = cursor->next;
   cursor->next = newNode;
   if (cursor == list->tail) {
      list->tail = newNode;
   }
}

Node_t* llUnlinkAfter(LinkedList_t* list, Node_t* cursor)
{
   Node_t* unlink = cursor->next;
   if (unlink != NULL) {
      cursor->next = unlink->next;
      unlink->next = NULL;
   }
   if (cursor->next == NULL) {
      list->tail = cursor;
   }

   return unlink;
}

void llPush(LinkedList_t* list, ItemType value)
{
   llLinkAfter(list, list->head, nodeCreate(value));
}

void llAppend(LinkedList_t* list, ItemType value)
{
   llLinkAfter(list, list->tail, nodeCreate(value));
}

ItemType llHead(const LinkedList_t list)
{
   assert(!llIsEmpty(list));
   return list.head->next->data;
}

ItemType llPop(LinkedList_t* list)
{
   assert(!llIsEmpty(*list));
   Node_t* top = llUnlinkAfter(list, list->head);
   ItemType value = top->data;
   free(top);
   return value;
}

