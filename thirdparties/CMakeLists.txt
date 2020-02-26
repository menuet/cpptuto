
add_library(thirdparty_catch2 INTERFACE)
target_include_directories(thirdparty_catch2 INTERFACE catch2/inc)
add_library(Catch2::Catch2 ALIAS thirdparty_catch2)

add_library(thirdparty_fmt SHARED fmt/src/format.cc)
target_compile_definitions(thirdparty_fmt PRIVATE FMT_EXPORT INTERFACE FMT_SHARED)
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_compile_options(thirdparty_fmt PUBLIC /wd4273)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    target_compile_options(thirdparty_fmt PUBLIC
        -Wno-nonportable-system-include-path
        -Wno-sign-conversion
        -Wno-missing-variable-declarations
        -Wno-unused-member-function
        )
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(thirdparty_fmt PUBLIC
        -Wno-deprecated-declarations
        -Wno-unknown-pragmas
        )
endif()
target_include_directories(thirdparty_fmt PUBLIC fmt/inc)
add_library(fmt::fmt ALIAS thirdparty_fmt)

add_library(thirdparty_date INTERFACE)
target_include_directories(thirdparty_date INTERFACE date/inc)
add_library(date::date ALIAS thirdparty_date)

if("${CMAKE_HOST_SYSTEM_NAME}" STREQUAL "Windows")
    add_library(thirdparty_date_tz date/src/tz.cpp)
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        target_compile_options(thirdparty_date_tz PUBLIC
            -Wno-nonportable-system-include-path
            -Wno-shadow-field-in-constructor
            -Wno-exit-time-destructors
            -Wno-unused-macros
            )
    endif()
    target_include_directories(thirdparty_date_tz PUBLIC date/inc)
    add_library(date::tz ALIAS thirdparty_date_tz)
endif()

add_library(thirdparty_tl INTERFACE)
target_include_directories(thirdparty_tl INTERFACE tl/inc)
add_library(tl::expected ALIAS thirdparty_tl)
