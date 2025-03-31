add_subdirectory(Audio)
add_subdirectory(Core)
add_subdirectory(Models)
add_subdirectory(Shapes)
add_subdirectory(Texts)
add_subdirectory(Textures)

set(SRC_RAYLIB
    ${SRC_RAYLIB_AUDIO}
    ${SRC_RAYLIB_CORE}
    ${SRC_RAYLIB_MODELS}
    ${SRC_RAYLIB_SHAPES}
    ${SRC_RAYLIB_TEXT}
    ${SRC_RAYLIB_TEXTURES} PARENT_SCOPE)