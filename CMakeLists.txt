cmake_minimum_required(VERSION 3.15)
project(GameProject VERSION 1.0 LANGUAGES CXX)

# Require C++17 or later (common for modern JSON parsing)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the executable and compile all .cpp files
add_executable(Crawler
    main.cpp
    enemies.cpp
    helper.cpp
    player.cpp
    renderer.cpp
)

# Look for headers in the current directory
target_include_directories(Crawler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Optional: Automatically copy leveldata.json to your build folder 
# so the executable can find it at runtime
configure_file(leveldata.json leveldata.json COPYONLY)
