#include "vector.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vector_init(Vector *vector, size_t elem_size) {
    assert(vector != NULL);
    vector->size = 0;
    vector->capacity = 4;
    vector->elem_size = elem_size;
    vector->data = malloc(vector->capacity * elem_size);
    if (vector->data == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
}

void vector_reserve(Vector *vector, size_t new_capacity) {
    assert(vector != NULL);
    if (new_capacity > vector->capacity) {
        void *new_data = realloc(vector->data, new_capacity * vector->elem_size);
        if (new_data == NULL) {
            fprintf(stderr, "Failed to reallocate memory\n");
            exit(EXIT_FAILURE);
        }
        vector->data = new_data;
        vector->capacity = new_capacity;
    }
}

void vector_add(Vector *vector, const void *value) {
    assert(vector != NULL);
    if (vector->size == vector->capacity) {
        vector_reserve(vector, vector->capacity == 0 ? 4 : vector->capacity * 2);
    }
    void *target = (char *)vector->data + (vector->size * vector->elem_size);
    memcpy(target, value, vector->elem_size);
    vector->size++;
}

const void *vector_get(const Vector *vector, size_t index) {
    assert(vector != NULL);
    assert(index < vector->size);  // Ensure index is within bounds
    return (char *)vector->data + (index * vector->elem_size);
}

void vector_set(Vector *vector, size_t index, const void *value) {
    assert(vector != NULL);
    assert(index < vector->size);  // Ensure index is within bounds
    void *target = (char *)vector->data + (index * vector->elem_size);
    memcpy(target, value, vector->elem_size);
}

void vector_free(Vector *vector) {
    assert(vector != NULL);
    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    vector->elem_size = 0;
}

size_t vector_size(const Vector *vector) {
    assert(vector != NULL);
    return vector->size;
}

size_t vector_capacity(const Vector *vector) {
    assert(vector != NULL);
    return vector->capacity;
}
