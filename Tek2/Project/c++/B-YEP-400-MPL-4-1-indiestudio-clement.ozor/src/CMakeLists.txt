add_subdirectory(Raylib)
add_subdirectory(Game)
add_subdirectory(Map)

file(GLOB SRC "main.cpp")
set(SRC ${SRC} ${SRC_RAYLIB} ${SRC_GAME} ${SRC_MAP} PARENT_SCOPE)
