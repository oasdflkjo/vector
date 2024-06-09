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

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_vector_init),
        cmocka_unit_test(test_vector_add),
        cmocka_unit_test(test_vector_set),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
