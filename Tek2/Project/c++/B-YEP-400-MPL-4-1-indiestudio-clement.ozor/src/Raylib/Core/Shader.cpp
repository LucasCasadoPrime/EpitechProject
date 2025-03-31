/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Shader.cpp
*/

#include "Shader.hpp"

Raylib::Core::ShaderB::ShaderB(const std::string &vsFileName, const std::string &fsFileName)
{
    _shader = LoadShader(vsFileName.c_str(), fsFileName.c_str());
}

Raylib::Core::ShaderB::~ShaderB() {
    UnloadShader(_shader);
}

int Raylib::Core::ShaderB::getShaderLocation(const std::string &uniformName) const {
    return GetShaderLocation(_shader, uniformName.c_str());
}

int Raylib::Core::ShaderB::getShaderLocationAttrib(const std::string &attribName) const {
    return GetShaderLocationAttrib(_shader, attribName.c_str());
}

void Raylib::Core::ShaderB::setShaderValue(int locIndex, const void *value, int uniformType) {
    SetShaderValue(_shader, locIndex, value, uniformType);
}

void Raylib::Core::ShaderB::setShaderValueV(int locIndex, const void *value, int uniformType, int count) {
    SetShaderValueV(_shader, locIndex, value, uniformType, count);
}

void Raylib::Core::ShaderB::setShaderValueMatrix(int locIndex, Matrix mat) {
    SetShaderValueMatrix(_shader, locIndex, mat);
}

void Raylib::Core::ShaderB::setShaderValueTexture(int locIndex, Texture2D texture) {
    SetShaderValueTexture(_shader, locIndex, texture);
}