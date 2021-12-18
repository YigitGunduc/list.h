#include <stdio.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

void_typed make_void_typed_impl(void_type_id id, void* ptr)
{
  return (void_typed) { .id = id, ptr = (void*) ptr };
}

struct node *list() {
  struct node *head = NULL;

  return head;
}

void del(struct node** head_ref) {
  struct node * head = *head_ref;
  head = head->next;
  return;
}

void clear(struct node **head_ref)
{
  *head_ref = NULL;
}

bool isEmpty(struct node** head_ref) {
  struct node *head = *head_ref;
  return head == NULL;
}

int length(struct node** head_ref) {
  struct node * head = *head_ref;
  int length = 0;
  struct node *current;

  for(current = head; current != NULL; current = current->next) {
   length++;
  }

  return length;
}

void printList(struct node ** head ) {
  struct node *ptr = *head;

  printf("[ ");

  while(ptr != NULL) {
    if (ptr->key.id == VT_INT)
    {
      printf("(%i) ",*(int*)ptr->key.ptr);
      ptr = ptr->next;
    }
    else if (ptr->key.id == VT_CHAR)
    {
      printf("(%c) ",*(int*)ptr->key.ptr);
      ptr = ptr->next;
    }
    else if (ptr->key.id == VT_DOUBLE)
    {
      printf("(%f) ",*(float*)ptr->key.ptr);
      ptr = ptr->next;
    }
    else if (ptr->key.id == VT_FLOAT)
    {
      printf("(%f) ",*(double*)ptr->key.ptr);
      ptr = ptr->next;
    }
  }
  printf(" ]");
  puts("");
}

void pop(struct node** head_ref)
{
  struct node *head = *head_ref;
  if(head != NULL) {
    
    if(head->next == NULL) {
      head = NULL;
    } else {
      
      struct node *temp = head;
      while(temp->next->next != NULL)
        temp = temp->next;
      
      struct node *lastNode = temp->next;
      temp->next = NULL;
      free(lastNode); 
    }
  }
}

void *get(struct node **head, int index) 
{
  struct node *current = *head;
 
  int count = 0;
  while (current != NULL) {
    if (count == index)
       return (current->key.ptr);
    count++;
    current = current->next;
  }

  assert(0);
}

// --- Append ---

void _append(struct node **head, void_typed val)
{
   struct node *newNode = malloc(sizeof(struct node));
   newNode->key = val;
   newNode->next = NULL;

   if(*head == NULL)
      *head = newNode;

   else
   {
      struct node *lastNode = *head;

      while(lastNode->next != NULL)
      {
         lastNode = lastNode->next;
      }

      lastNode->next = newNode;
   }

}

void append_int_ptr(struct node **head, int* ptr)
{
   void_typed value = make_void_typed(ptr);
   _append(head, value);
   return;
}

void append_char_ptr(struct node **head, char* ptr)
{
   void_typed value = make_void_typed(ptr);
   _append(head, value);
   return;
}

void append_float_ptr(struct node **head, float* ptr)
{
   void_typed value = make_void_typed(ptr);
   _append(head, value);
   return;
}

void append_double_ptr(struct node **head, double* ptr)
{
   void_typed value = make_void_typed(ptr);
   _append(head, value);
   return;
}

// --- Find ---

int find_int_ptr(struct node** head_ref, int *key) 
{

  struct node * head = *head_ref;
  //start from the first link
  struct node* current = head;

  //if list is empty
  if(head == NULL) {
    return -1;
  }

  int index = 0;
  while(*(int*)current->key.ptr != *(int*)key) {

  if(current->next == NULL) {
    return -1;
  } else {
    current = current->next;
    index++;
  }
}    

    return index;
}

int find_char_ptr(struct node** head_ref, char* key) 
{

  struct node * head = *head_ref;
  //start from the first link
  struct node* current = head;

  //if list is empty
  if(head == NULL) {
    return -1;
  }

  int index = 0;
  while(*(char*)current->key.ptr != *(char*)key) {

    if(current->next == NULL) {
      return -1;
    } else {
      current = current->next;
      index++;
    }
  }    

  return index;
}

int find_double_ptr(struct node** head_ref, double *key) 
{

  struct node * head = *head_ref;
  //start from the first link
  struct node* current = head;

  //if list is empty
  if(head == NULL) {
    return -1;
  }

  int index = 0;
  while(*(double*)current->key.ptr != *(double*)key) {

    if(current->next == NULL) {
      return -1;
    } else {
      current = current->next;
      index++;
    }
  }    

  return index;
}

int find_float_ptr(struct node** head_ref, float *key) 
{

  struct node * head = *head_ref;
  //start from the first link
  struct node* current = head;

  //if list is empty
  if(head == NULL) {
    return -1;
  }

  int index = 0;
  while(*(float*)current->key.ptr != *(float*)key) {

    if(current->next == NULL) {
      return -1;
    } else {
      current = current->next;
      index++;
    }
  }    

  return index;
}

// --- Delete ---

void delete_int_ptr(struct node** head_ref, int *key) {
  struct node * head = *head_ref;

  //start from the first link
  struct node* current = head;
  struct node* previous = NULL;

  //if list is empty
  if(head == NULL) {
    return;
  }

  //navigate through list
  while(*(int*)current->key.ptr != *(int*)key) {

    //if it is last node
    if(current->next == NULL) {
      return;
    } else {
      //store reference to current link
      previous = current;
      //move to next link
      current = current->next;
    }
  }

  //found a match, update the link
  if(current == head) {
    //change first to point to next link
    head = head->next;
  } else {
    //bypass the current link
    previous->next = current->next;
  }   
}

void delete_float_ptr(struct node** head_ref, float *key) {
  struct node * head = *head_ref;

  //start from the first link
  struct node* current = head;
  struct node* previous = NULL;

  //if list is empty
  if(head == NULL) {
    return;
  }

  //navigate through list
  while(*(float*)current->key.ptr != *(float*)key) {

    //if it is last node
    if(current->next == NULL) {
      return;
    } else {
      //store reference to current link
      previous = current;
      //move to next link
      current = current->next;
    }
  }

  //found a match, update the link
  if(current == head) {
    //change first to point to next link
    head = head->next;
  } else {
    //bypass the current link
    previous->next = current->next;
  }   
}

void delete_double_ptr(struct node** head_ref, double *key) {
  struct node * head = *head_ref;

  //start from the first link
  struct node* current = head;
  struct node* previous = NULL;

  //if list is empty
  if(head == NULL) {
    return;
  }

  //navigate through list
  while(*(double*)current->key.ptr != *(double*)key) {

    //if it is last node
    if(current->next == NULL) {
      return;
    } else {
      //store reference to current link
      previous = current;
      //move to next link
      current = current->next;
    }
  }

  //found a match, update the link
  if(current == head) {
    //change first to point to next link
    head = head->next;
  } else {
    //bypass the current link
    previous->next = current->next;
  }   
}

void delete_char_ptr(struct node** head_ref, char *key) {
  struct node * head = *head_ref;

  //start from the first link
  struct node* current = head;
  struct node* previous = NULL;

  //if list is empty
  if(head == NULL) {
    return;
  }

  //navigate through list
  while(*(char*)current->key.ptr != *(char*)key) {

    //if it is last node
    if(current->next == NULL) {
      return;
    } else {
      //store reference to current link
      previous = current;
      //move to next link
      current = current->next;
    }
  }

  //found a match, update the link
  if(current == head) {
    //change first to point to next link
    head = head->next;
  } else {
    //bypass the current link
    previous->next = current->next;
  }   
}

// --- Sort ---

void sort(struct node** head_ref) {

  struct node * head = *head_ref;
  int i, j, k, tempData;
  struct node *current;
  struct node *next;

  int size = length(head_ref);
  k = size ;

  for ( i = 0 ; i < size - 1 ; i++, k-- ) {
    current = head;
    next = head->next;

    for ( j = 1 ; j < k ; j++ ) {  

      if ( *(int*)current->key.ptr > *(int*)next->key.ptr ) {
        tempData = *(int*)current->key.ptr;
        current->key = next->key;
        next->key.ptr = &tempData;

      }

      current = current->next;
      next = next->next;
    }
  }  
}

void reverse(struct node** head_ref) 
{
  struct node* prev  = NULL;
  struct node* current = *head_ref;
  struct node* next;

  while (current != NULL) {
    next  = current->next;
    current->next = prev;  
    prev = current;
    current = next;
  }

  *head_ref = prev;
}
