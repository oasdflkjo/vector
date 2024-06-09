cmake_minimum_required(VERSION 3.10)
project(VectorProject C)

set(CMAKE_C_STANDARD 99)

# Add source files
add_library(vector STATIC src/vector.c)

# Include directories
target_include_directories(vector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add CMocka for unit testing
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(CMocka REQUIRED)

# Add test executable
add_executable(test_vector test/test_vector.c)

# Link the vector library and CMocka to the test executable
target_link_libraries(test_vector vector ${CMOCKA_LIBRARIES})

# Include directories for tests
target_include_directories(test_vector PRIVATE ${CMOCKA_INCLUDE_DIRS})

# Enable testing
enable_testing()
add_test(NAME test_vector COMMAND test_vector)
