/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Shader.hpp
*/

#ifndef BOMBERMAN_SHADER_HPP
#define BOMBERMAN_SHADER_HPP

// TODO:
//Shader LoadShaderFromMemory(const char *vsCode, const char *fsCode);    // Load shader from code strings and bind default locations
#include "raylib.h"
#include "Essentials.hpp"

namespace Raylib {
    namespace Core {
        class ShaderB {
            public:
                ShaderB(const std::string &vsFileName, const std::string &fsFileName);
                ~ShaderB();

                int getShaderLocation(const std::string &uniformName) const;
                int getShaderLocationAttrib(const std::string &attribName) const;
                void setShaderValue(int locIndex, const void *value, int uniformType);
                void setShaderValueV(int locIndex, const void *value, int uniformType, int count);
                void setShaderValueMatrix(int locIndex, Matrix mat);
                void setShaderValueTexture(int locIndex, Texture2D texture);

            private:
                Shader _shader;
        };
    }
}

#endif
