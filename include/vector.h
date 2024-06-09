#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    size_t elem_size;
} Vector;

// Initialize the vector with the element size
void vector_init(Vector *vector, size_t elem_size);

// Reserve memory for a given capacity
void vector_reserve(Vector *vector, size_t new_capacity);

// Add an element to the vector
void vector_add(Vector *vector, void *value);

// Get an element at a specific index
void *vector_get(Vector *vector, size_t index);

// Set an element at a specific index
void vector_set(Vector *vector, size_t index, void *value);

// Free the memory allocated for the vector
void vector_free(Vector *vector);

// Print elements of the vector assuming they are integers
void vector_print_int(Vector *vector);

#endif // VECTOR_H
