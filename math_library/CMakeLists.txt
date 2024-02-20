
# list of source files
set(lib_src mathlib.h mathlib.cpp)

# this is the "object library" target: compiles the sources only once
add_library(objlib OBJECT ${lib_src})

# shared libraries need PIC
set_property(TARGET objlib PROPERTY POSITION_INDEPENDENT_CODE 1)

#for windows, export all symbols
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)


#static library target
add_library(math_library_static STATIC $<TARGET_OBJECTS:objlib>)

#shared library target
add_library(math_library_shared SHARED $<TARGET_OBJECTS:objlib>)

#path of library for post build copy
set(MATH_LIBRARY_PATH "/home/eric/temp/math_library" CACHE STRING "math lib path" FORCE)

#post build, copy static to library path
add_custom_command(TARGET math_library_static POST_BUILD
        # Copy the binary to the desired path
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:math_library_static> ${MATH_LIBRARY_PATH}/static
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/mathlib.h ${MATH_LIBRARY_PATH}/include
        )

#post build, copy shared to library path
add_custom_command(TARGET math_library_shared POST_BUILD
        # Copy the binary to the desired path
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:math_library_shared> ${MATH_LIBRARY_PATH}/shared
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/mathlib.h ${MATH_LIBRARY_PATH}/include
        )

#for WIN, copy the stub library to library path
if (WIN32)
    add_custom_command(TARGET math_library_shared POST_BUILD
            # Copy the binary to the desired path
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/math_library_shared.lib ${MATH_LIBRARY_PATH}/shared
            )
endif ()
