cmake_minimum_required (VERSION 3.8)

project ("howto_cpp_library")

#the math library
add_subdirectory ("math_library")

#client linked with static version of library
add_subdirectory ("math_library_client_static")

#client linked with shared version of library
add_subdirectory ("math_library_client_shared")
