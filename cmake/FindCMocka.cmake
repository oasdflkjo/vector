# - Try to find the CMocka library
# Once done, this will define
#  CMOCKA_FOUND - system has CMocka
#  CMOCKA_INCLUDE_DIRS - the CMocka include directories
#  CMOCKA_LIBRARIES - link these to use CMocka

find_path(CMOCKA_INCLUDE_DIR cmocka.h
  PATHS /usr/local/include /usr/include /opt/local/include
)

find_library(CMOCKA_LIBRARY NAMES cmocka
  PATHS /usr/local/lib /usr/lib /opt/local/lib
)

if (CMOCKA_INCLUDE_DIR AND CMOCKA_LIBRARY)
  set(CMOCKA_FOUND TRUE)
  set(CMOCKA_LIBRARIES ${CMOCKA_LIBRARY})
  set(CMOCKA_INCLUDE_DIRS ${CMOCKA_INCLUDE_DIR})
else()
  set(CMOCKA_FOUND FALSE)
endif()

mark_as_advanced(CMOCKA_INCLUDE_DIR CMOCKA_LIBRARIES)
