#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    size_t elem_size;
} Vector;

void vector_init(Vector *vector, size_t elem_size);
void vector_add(Vector *vector, void *value);
void *vector_get(Vector *vector, size_t index);
void vector_set(Vector *vector, size_t index, void *value);
void vector_free(Vector *vector);
void vector_print_int(Vector *vector);

#endif // VECTOR_H
