/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Draw.cpp
*/

#include "Draw.hpp"

Raylib::Core::Draw::Draw() {}

Raylib::Core::Draw::~Draw() {}

void Raylib::Core::Draw::clearBackground(Color color) {
    ClearBackground(color);
}

void Raylib::Core::Draw::begin() {
    BeginDrawing();
}

void Raylib::Core::Draw::end() {
    EndDrawing();
}

void Raylib::Core::Draw::beginMode2D(Camera2D camera) {
    BeginMode2D(camera);
}

void Raylib::Core::Draw::endMode2D() {
    EndMode2D();
}

void Raylib::Core::Draw::beginMode3D(Camera3D camera) {
    BeginMode3D(camera);
}

void Raylib::Core::Draw::endMode3D() {
    EndMode3D();
}

void Raylib::Core::Draw::beginTextureMode(RenderTexture2D target) {
    BeginTextureMode(target);
}

void Raylib::Core::Draw::endTextureMode() {
    EndTextureMode();
}

void Raylib::Core::Draw::beginShaderMode(Shader shader) {
    BeginShaderMode(shader);
}

void Raylib::Core::Draw::endShaderMode() {
    EndShaderMode();
}

void Raylib::Core::Draw::beginBlendMode(int mode) {
    BeginBlendMode(mode);
}

void Raylib::Core::Draw::beginScissorMode(int x, int y, int width, int height) {
    BeginScissorMode(x, y, width, height);
}

void Raylib::Core::Draw::endScissorMode() {
    EndScissorMode();
}

void Raylib::Core::Draw::beginVrStereoMode(VrStereoConfig config) {
    BeginVrStereoMode(config);
}

void Raylib::Core::Draw::endVrStereoMode() {
    EndVrStereoMode();
}