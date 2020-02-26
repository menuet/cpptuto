
add_executable(quickcheat
    auto.cpp
    classes.cpp
    conditions_and_loops.cpp
    constants.cpp
    containers.cpp
    conversions.cpp
    date_and_time.cpp
    dynamic_allocation.cpp
    enum_struct_class.cpp
    exceptions.cpp
    functions.cpp
    function_main.cpp
    function_objects.cpp
    initialization.cpp
    inputs_and_outputs.cpp
    namespaces_and_using.cpp
    pointers_and_arrays.cpp
    preprocessor.cpp
    preprocessor.hpp
    references.cpp
    scope_storage_lifetime.cpp
    strings.cpp
    templates.cpp
    threads.cpp
    types_algebraic.cpp
    types_fundamental.cpp
    )

add_test(NAME quickcheat COMMAND quickcheat --durations yes)

target_link_libraries(quickcheat PRIVATE Threads::Threads tl::expected date::date fmt::fmt Catch2::Catch2)
if("${CMAKE_HOST_SYSTEM_NAME}" STREQUAL "Windows")
    target_link_libraries(quickcheat PRIVATE date::tz)
endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_compile_options(quickcheat PRIVATE /wd4189 /wd4459 /wd4244 /wd4505 /wd4101 /wd4700)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        target_compile_options(quickcheat PRIVATE -Wno-maybe-uninitialized)
    else()
        target_compile_options(quickcheat PRIVATE
            -Wno-uninitialized
            -Wno-exit-time-destructors
            -Wno-missing-variable-declarations
            -Wno-shadow-field-in-constructor
            -Wno-global-constructors
            -Wno-old-style-cast
            -Wno-unused-parameter
            -Wno-unused-member-function
            -Wno-unneeded-member-function
            -Wno-ctad-maybe-unsupported
            -Wno-sign-conversion
            -Wno-missing-field-initializers
            -Wno-unused-exception-parameter
            -Wno-unused-private-field
            -Wno-extra-semi-stmt
            )
    endif()
    target_compile_options(quickcheat PRIVATE -Wno-unused-function -Wno-unused-variable)
endif()
