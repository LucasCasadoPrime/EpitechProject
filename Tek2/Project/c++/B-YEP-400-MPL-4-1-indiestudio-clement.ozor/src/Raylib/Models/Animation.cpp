/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Animation.cpp
*/

#include "Animation.hpp"

Raylib::Models::Animation::Animation(const std::string &fileName, unsigned int *animCount) {
    _animations = LoadModelAnimations(fileName.c_str(), animCount);
    _animCount = *animCount;
}

Raylib::Models::Animation::~Animation() {
    UnloadModelAnimations(_animations, _animCount);
}

void Raylib::Models::Animation::updateModelAnimation(Model model, ModelAnimation anim, int frame) {
    UpdateModelAnimation(model, anim, frame);
}

bool Raylib::Models::Animation::isModelAnimationValid(Model model, ModelAnimation anim) {
    return IsModelAnimationValid(model, anim);
}