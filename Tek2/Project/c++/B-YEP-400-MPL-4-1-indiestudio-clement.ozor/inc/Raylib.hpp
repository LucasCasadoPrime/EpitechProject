/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Raylib.hpp
*/

#ifndef INDIESTUDIO_RAYLIB_HPP
#define INDIESTUDIO_RAYLIB_HPP

#if _WIN32
    #include "..\src\Raylib\Core\Core.hpp"
    #include "..\src\Raylib\Models\Models.hpp"
    #include "..\src\Raylib\Texts\Texts.hpp"
    #include "..\src\Raylib\Textures\Image.hpp"
    #include "..\src\Raylib\Textures\Texture.hpp"
    #include "..\src\Raylib\Audio\Audios.hpp"
#else
    #include "../src/Raylib/Core/Core.hpp"
    #include "../src/Raylib/Models/Models.hpp"
    #include "../src/Raylib/Texts/Texts.hpp"
    #include "../src/Raylib/Textures/Image.hpp"
    #include "../src/Raylib/Textures/Texture.hpp"
    #include "../src/Raylib/Audio/Audios.hpp"
#endif

#endif
