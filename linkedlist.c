#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int key;
   struct node *next;
};


//display the list
void printList(struct node ** head ) {
   struct node *ptr = *head;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d) ",ptr->key);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//insert link at the first location
void insertFirst(struct node ** head, int key) {
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->key = key;
	
   //point it to old first node
   link->next = *head;
   
   /*printf("(%d) ",link->key);*/
	
   *head = link;
}

//delete first item
struct node* deleteFirst(struct node** head_ref) {
    struct node * head = *head_ref;

   //save reference to first link
   struct node *tempLink = head;
	
   //mark next to first link as first 
   head = head->next;
	
   //return the deleted link
   return tempLink;
}

//is list empty
bool isEmpty(struct node** head_ref) {
    struct node * head = *head_ref;
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

int find(struct node** head_ref, int key) {

    struct node * head = *head_ref;
   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return -1;
   }

   int index = 0;
   //navigate through list
   while(current->key != key) {
	
      //if it is last node
      if(current->next == NULL) {
         return -1;
      } else {
         //go to next link
         current = current->next;
         index++;
      }
   }      
	
   return index;
}

//delete a link with given key
struct node* delete(struct node** head_ref, int key) {
    struct node * head = *head_ref;

   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
	
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
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
	
   return current;
}

void sort(struct node** head_ref) {

    struct node * head = *head_ref;
   int i, j, k, tempKey, tempData;
   struct node *current;
   struct node *next;
	
   int size = length(head_ref);
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current->key > next->key ) {
            tempData = current->key;
            current->key = next->key;
            next->key = tempData;

         }
			
         current = current->next;
         next = next->next;
      }
   }   
}

void reverse(struct node** head_ref) {
   struct node* prev   = NULL;
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

int main() {
   struct node *head = NULL;
   insertFirst(&head, 10);
   insertFirst(&head, 20);
   insertFirst(&head, 30);
   insertFirst(&head, 1);
   insertFirst(&head, 40);
   insertFirst(&head, 56); 

   printf("Original List: "); 
	
   //print list
   printList(&head);

   /*while(!isEmpty(&head)) {            */
      /*struct node *temp = deleteFirst(&head);*/
      /*printf("\nDeleted value:");*/
      /*printf("(%d) ",temp->key);*/
   /*}  */
	
   /*printf("\nList after deleting all items: ");*/
   /*printList(head);*/
   /*insertFirst(head, 10);*/
   /*insertFirst(head, 20);*/
   /*insertFirst(head, 30);*/
   /*insertFirst(head, 1);*/
   /*insertFirst(head, 40);*/
   /*insertFirst(head, 56); */
   
   /*printf("\nRestored List: ");*/
   /*printList(head);*/
   /*printf("\n");  */

   /*struct node *foundLink = find(&head, 4);*/
   int index = find(&head, 40);
   printf("index is: %i", index);
	
   /*if(foundLink != NULL) {*/
      /*printf("Element found: ");*/
      /*printf("(%d) ",foundLink->key);*/
      /*printf("\n");  */
   /*} else {*/
      /*printf("Element not found.");*/
   /*}*/

   /*delete(&head, 4);*/
   /*printf("List after deleting an item: ");*/
   /*printList(head);*/
   /*printf("\n");*/
   /*foundLink = find(&head,4);*/
	
   /*if(foundLink != NULL) {*/
      /*printf("Element found: ");*/
      /*printf("(%d) ",foundLink->key);*/
      /*printf("\n");*/
   /*} else {*/
      /*printf("Element not found.");*/
   /*}*/
	
   printf("\n");
   sort(&head);
	
   printf("List after sorting the data: ");
   printList(&head);
	
   reverse(&head);
   printf("\nList after reversing the data: ");
   printList(&head);

   return 0;
}
