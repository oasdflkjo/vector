#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void vector_init(Vector *vector, size_t elem_size) {
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

void vector_add(Vector *vector, void *value) {
    if (vector == NULL) {
        fprintf(stderr, "Vector is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (vector->size == vector->capacity) {
        vector_reserve(vector, vector->capacity == 0 ? 4 : vector->capacity * 2);
    }
    void *target = (char*)vector->data + (vector->size * vector->elem_size);
    memcpy(target, value, vector->elem_size);
    vector->size++;
}

inline void *vector_get(Vector *vector, size_t index) {
    if (index >= vector->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    return (char*)vector->data + (index * vector->elem_size);
}

inline void vector_set(Vector *vector, size_t index, void *value) {
    if (index >= vector->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    void *target = (char*)vector->data + (index * vector->elem_size);
    memcpy(target, value, vector->elem_size);
}

void vector_free(Vector *vector) {
    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    vector->elem_size = 0;
}

void vector_print_int(Vector *vector) {
    for (size_t i = 0; i < vector->size; i++) {
        printf("%d ", *(int*)vector_get(vector, i));
    }
    printf("\n");
}
