# TODO Aufgabe 1:
add_library(GameObjects Missile.cpp PlayerSea.cpp Ship.cpp)

target_link_libraries(GameObjects Sea)

target_include_directories(GameObjects PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
