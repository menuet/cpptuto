
add_executable(musify-account
    main.cpp
    accounts.cpp
    accounts.hpp
    )

target_link_libraries(musify-account PRIVATE fmt::fmt musify-holdall)
