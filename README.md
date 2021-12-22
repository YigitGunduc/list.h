

## Getting Started

Building project dependents on the list.h
```c
gcc SOURCES list.c
```

Initializing a new list

```c
struct node *head = list();
```

Adding a new element to the list
```c
char item1 = 'a';
int item2 = 43;
float item3 = 12.32;
double item4 = 5432.312;

append(&head, &item1);
append(&head, &item2);
append(&head, &item3);
append(&head, &item4);
```

Other usefull utilies
```c
// general utils
int length(struct node** head_ref); // returns the length of the arr
void del(struct node** head_ref); // delets the last item
void clear(struct node **head_ref); // cleans the array
bool isEmpty(struct node** head_ref); // checks if the array is empty or not
void printList(struct node ** head); // prints the list
void pop(struct node** head_ref); // pops the first item

// --- Sort ---
void sort(struct node** head_ref); // sorts the given array

// --- reverse ---
void reverse(struct node** head_ref); // reverses the array
```

