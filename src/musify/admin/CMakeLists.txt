
add_executable(musify-admin
    main.cpp
    admin.hpp
    )

target_link_libraries(musify-admin PRIVATE musify-holdall)
