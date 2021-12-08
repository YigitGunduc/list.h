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

extern inline void_typed make_void_typed_impl(void_type_id id, void* ptr) {
  return (void_typed) { .id = id, ptr = (void*) ptr };
}

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
