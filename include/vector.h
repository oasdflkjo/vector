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
 * Initializes the vector.
 * 
 * @param vector Pointer to the vector.
 * @param elem_size Size of each element in the vector.
 */
void vector_init(Vector *vector, size_t elem_size);

/**
 * Ensures the vector has at least new_capacity capacity.
 * 
 * @param vector Pointer to the vector.
 * @param new_capacity New capacity to ensure.
 */
void vector_reserve(Vector *vector, size_t new_capacity);

/**
 * Adds a new element to the vector.
 * 
 * @param vector Pointer to the vector.
 * @param value Pointer to the value to add.
 */
void vector_add(Vector *vector, const void *value);

/**
 * Retrieves an element at a specified index.
 * 
 * @param vector Pointer to the vector.
 * @param index Index of the element to retrieve.
 * @return Pointer to the element.
 */
const void *vector_get(const Vector *vector, size_t index);

/**
 * Sets the value at a specified index.
 * 
 * @param vector Pointer to the vector.
 * @param index Index of the element to set.
 * @param value Pointer to the value to set.
 */
void vector_set(Vector *vector, size_t index, const void *value);

/**
 * Frees the allocated memory for the vector.
 * 
 * @param vector Pointer to the vector.
 */
void vector_free(Vector *vector);

/**
 * Returns the current size of the vector.
 * 
 * @param vector Pointer to the vector.
 * @return Size of the vector.
 */
size_t vector_size(const Vector *vector);

/**
 * Returns the current capacity of the vector.
 * 
 * @param vector Pointer to the vector.
 * @return Capacity of the vector.
 */
size_t vector_capacity(const Vector *vector);

#endif // VECTOR_H
