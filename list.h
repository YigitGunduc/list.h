#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef enum {
  VT_INT,
  VT_CHAR,
  VT_FLOAT,
  VT_DOUBLE
} void_type_id;

typedef struct {
  void_type_id id;
  void *ptr;
} void_typed;

struct node {
  void_typed key;
  struct node *next;
};

#define vt_id(ptr) _Generic((ptr),\
        char*: VT_CHAR, \
        int*:  VT_INT, \
        float*: VT_FLOAT, \
        double*: VT_DOUBLE)

#define make_void_typed(ptr) \
  make_void_typed_impl(vt_id(ptr), ptr)

#define append(head, item) _Generic((item), \
        float*: append_float_ptr, \
        char*: append_char_ptr, \
        int*: append_int_ptr, \
        double*: append_double_ptr \
        )(head, item)

#define find(head, item) _Generic((item), \
        float*: find_float_ptr, \
        char*: find_char_ptr, \
        int*: find_int_ptr, \
        double*: find_double_ptr \
        )(head, item)

#define delete_(head, item) _Generic((item), \
        float*: delete_float_ptr, \
        char*: delete_char_ptr, \
        int*: delete_int_ptr, \
        double*: delete_double_ptr \
        )(head, item)

// functions

// init
struct node *list();
// general utils
int length(struct node** head_ref);
void del(struct node** head_ref);
void clear(struct node **head_ref);
bool isEmpty(struct node** head_ref);
void printList(struct node ** head);
void pop(struct node** head_ref);
// --- Append ---
void _append(struct node **head, void_typed val);
void append_int_ptr(struct node **head, int* ptr);
void append_char_ptr(struct node **head, char* ptr);
void append_float_ptr(struct node **head, float* ptr);
void append_double_ptr(struct node **head, double* ptr);
// --- Find ---
int find_int_ptr(struct node** head_ref, int *key) ;
int find_char_ptr(struct node** head_ref, char* key) ;
int find_double_ptr(struct node** head_ref, double *key) ;
int find_float_ptr(struct node** head_ref, float *key);
// --- Delete ---
void delete_int_ptr(struct node**head_ref, int *key);
void delete_float_ptr(struct node** head_ref, float *key);
void delete_double_ptr(struct node** head_ref, double *key);
void delete_char_ptr(struct node** head_ref, char *key);
// --- Sort ---
void sort(struct node** head_ref);
// --- reverse ---
void reverse(struct node** head_ref); 

#endif // LIST_H
