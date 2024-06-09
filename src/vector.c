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
}

void vector_add(Vector *vector, void *value) {
    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->data = realloc(vector->data, vector->capacity * vector->elem_size);
    }
    void *target = (char*)vector->data + (vector->size * vector->elem_size);
    memcpy(target, value, vector->elem_size);
    vector->size++;
}

void *vector_get(Vector *vector, size_t index) {
    assert(index < vector->size);
    return (char*)vector->data + (index * vector->elem_size);
}

void vector_set(Vector *vector, size_t index, void *value) {
    assert(index < vector->size);
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
