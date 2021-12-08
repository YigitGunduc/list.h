#include "list.h"
#include <stdio.h>

int append_char_ptr(int a, char* ptr)
{
    return 0;
}

int append_float_ptr(int a, float* ptr)
{
    return 0;
}

int append_int_ptr(int a, int* ptr)
{
    return 0;
}

int append_double_ptr(int a, double* ptr)
{
    void_typed value = make_void_typed(ptr);
    return (int) *(double*)value.ptr;
}

int main() {
    /*char *c_ptr = 0;*/
    /*int *i_ptr = 0;*/
    /*float a = 43;*/
    /*float *f_ptr = &a;*/

    /*void_typed va = make(c_ptr);*/
    /*void_typed vc = make_void_typed(c_ptr);*/
    /*void_typed vi = make_void_typed(i_ptr);*/
    /*void_typed vf = make_void_typed(f_ptr);*/

    /*printf("vc=(%d, %p)\n", (int)vc.id, vc.ptr);*/
    /*printf("vi=(%d, %p)\n", (int)vi.id, vc.ptr);*/
    /*printf("vf=(%d, %p)\n", (int)vf.id, vf.ptr);*/
    /*printf("va=(%d, %p)\n", (int)va.id, va.ptr);*/

    double test = 18.4;
    int value = append(1, (double*)&test);
    printf("%i\n", value);
}

