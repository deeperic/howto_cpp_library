#the path where the library is located
set(MATH_LIBRARY_PATH "/home/eric/temp/math_library" CACHE STRING "math lib path" FORCE)

#include path
include_directories("${MATH_LIBRARY_PATH}/include")

#lib path
link_directories("${MATH_LIBRARY_PATH}/static")

#add target for linking with static library
add_executable (math_client_static "math_client_static.cpp")

if (WIN32)
  #link with .lib
  target_link_libraries(math_client_static math_library_static.lib)
else ()
  #link with .a
  target_link_libraries(math_client_static math_library_static)
endif()