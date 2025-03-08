cmake_minimum_required(VERSION 3.2)
project(spectacular_cities)

# Znalezienie biblioteki ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Dodanie katalogu z plikami nagłówkowymi
include_directories(include src)

# Dodanie plików źródłowych
add_executable(spectacular_cities main.cpp src/main_menu.cpp)

set_property(TARGET spectacular_cities PROPERTY CXX_STANDARD 17)

# Linkowanie z ncurses
target_link_libraries(spectacular_cities ${CURSES_LIBRARIES} menu)