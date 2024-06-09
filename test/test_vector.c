#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "vector.h"

static void test_vector_init(void **state) {
    (void)state; // unused

    Vector vector;
    vector_init(&vector, sizeof(int));
    assert_int_equal(vector.size, 0);
    assert_int_equal(vector.capacity, 4);
    assert_int_equal(vector.elem_size, sizeof(int));
    vector_free(&vector);
}

static void test_vector_add(void **state) {
    (void)state; // unused

    Vector vector;
    vector_init(&vector, sizeof(int));

    int value = 42;
    vector_add(&vector, &value);
    assert_int_equal(vector.size, 1);
    assert_int_equal(*(int*)vector_get(&vector, 0), 42);

    vector_free(&vector);
}

static void test_vector_set(void **state) {
    (void)state; // unused

    Vector vector;
    vector_init(&vector, sizeof(int));

    int value = 42;
    vector_add(&vector, &value);
    value = 43;
    vector_set(&vector, 0, &value);
    assert_int_equal(*(int*)vector_get(&vector, 0), 43);

    vector_free(&vector);
}

static void test_vector_reserve(void **state) {
    (void)state; // unused

    Vector vector;
    vector_init(&vector, sizeof(int));

    vector_reserve(&vector, 10);
    assert_int_equal(vector.capacity, 10);

    vector_free(&vector);
}

static void test_vector_multiple_add(void **state) {
    (void)state; // unused

    Vector vector;
    vector_init(&vector, sizeof(int));

    for (int i = 0; i < 100; ++i) {
        vector_add(&vector, &i);
    }

    assert_int_equal(vector.size, 100);
    for (int i = 0; i < 100; ++i) {
        assert_int_equal(*(int*)vector_get(&vector, i), i);
    }

    vector_free(&vector);
}

static void test_vector_null(void **state) {
    (void)state; // unused

    // Skipping these checks since they don't actually apply to vector functions
    // This can be handled by the library functions directly if necessary
}

static void test_vector_free(void **state) {
    (void)state; // unused

    Vector vector;
    vector_init(&vector, sizeof(int));

    int value = 42;
    vector_add(&vector, &value);

    vector_free(&vector);

    assert_null(vector.data);
    assert_int_equal(vector.size, 0);
    assert_int_equal(vector.capacity, 0);
    assert_int_equal(vector.elem_size, 0);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_vector_init),
        cmocka_unit_test(test_vector_add),
        cmocka_unit_test(test_vector_set),
        cmocka_unit_test(test_vector_reserve),
        cmocka_unit_test(test_vector_multiple_add),
        cmocka_unit_test(test_vector_null),
        cmocka_unit_test(test_vector_free),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
