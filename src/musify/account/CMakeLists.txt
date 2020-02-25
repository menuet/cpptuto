
add_executable(musify-account main.cpp)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_compile_options(musify-account PRIVATE /wd4700)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    target_compile_options(musify-account PRIVATE -Wno-uninitialized)
endif()
