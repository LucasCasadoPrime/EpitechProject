add_subdirectory(Entities)
add_subdirectory(PowerUp)

file(GLOB SRC_GAME_MAIN "*.cpp")
set(SRC_GAME_MAIN ${SRC_GAME_MAIN} PARENT_SCOPE)

set(SRC_GAME ${SRC_GAME_MAIN} ${SRC_GAME_MAIN_ENTITIES} ${SRC_GAME_MAIN_POWERUP} PARENT_SCOPE)