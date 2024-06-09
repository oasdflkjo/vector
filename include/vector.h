#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    size_t elem_size;
} Vector;

/**
 * Initializes a vector.
 *
 * @param vector Pointer to the vector to initialize.
 * @param elem_size Size of each element in the vector.
 */
void vector_init(Vector *vector, size_t elem_size);

/**
 * Reserves capacity for at least new_capacity elements.
 *
 * @param vector Pointer to the vector to reserve capacity for.
 * @param new_capacity The new capacity to reserve.
 */
void vector_reserve(Vector *vector, size_t new_capacity);

/**
 * Adds an element to the vector.
 *
 * @param vector Pointer to the vector to add the element to.
 * @param value Pointer to the value to add.
 */
void vector_add(Vector *vector, void *value);

/**
 * Retrieves an element at the specified index.
 *
 * @param vector Pointer to the vector to retrieve the element from.
 * @param index The index of the element to retrieve.
 * @return Pointer to the retrieved element.
 */
void *vector_get(Vector *vector, size_t index);

/**
 * Sets an element at the specified index.
 *
 * @param vector Pointer to the vector to set the element in.
 * @param index The index of the element to set.
 * @param value Pointer to the value to set.
 */
void vector_set(Vector *vector, size_t index, void *value);

/**
 * Frees the memory allocated for the vector.
 *
 * @param vector Pointer to the vector to free.
 */
void vector_free(Vector *vector);

/**
 * Prints elements of the vector assuming they are integers.
 *
 * @param vector Pointer to the vector to print.
 */
void vector_print_int(Vector *vector);

#endif // VECTOR_H
