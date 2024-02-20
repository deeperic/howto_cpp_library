#the path where the library is located
set(MATH_LIBRARY_PATH "/home/eric/temp/math_library" CACHE STRING "math lib path" FORCE)

#include path
include_directories("${MATH_LIBRARY_PATH}/include")

#lib path
link_directories("${MATH_LIBRARY_PATH}/shared")

#add target for linking with shared library
add_executable (math_client_shared "math_client_shared.cpp")

if (WIN32)
    #for windows, link with the stub library
    target_link_libraries(math_client_shared math_library_shared.lib)
else ()
    #link with .so otherwise
    target_link_libraries(math_client_shared math_library_shared)
endif()
