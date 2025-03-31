/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Material.cpp
*/

#include "Material.hpp"

Raylib::Models::MaterialB::MaterialB(const std::string &fileName, int *materialCount) {
    _material = LoadMaterials(fileName.c_str(), materialCount);
}

Raylib::Models::MaterialB::~MaterialB() {
    UnloadMaterial(*_material);
}

Material Raylib::Models::MaterialB::loadMaterialDefault() {
    return LoadMaterialDefault();
}

void Raylib::Models::MaterialB::setMaterialTexture(int mapType, Texture2D texture) {
    SetMaterialTexture(_material, mapType, texture);
}

void Raylib::Models::MaterialB::setModelMeshMaterial(Model *model, int meshId, int materialId) {
    SetModelMeshMaterial(model, meshId, materialId);
}