/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Model.cpp
*/

#include "Model.hpp"

Raylib::Models::ModelB::ModelB(const std::string& modelpath, const std::string& texturepath, Vector3 position, Vector3 scale) {
    _path = modelpath;
    _model = LoadModel((modelpath + ".obj").c_str());
    _position = position;
    _scale = scale;
    this->setTexture(texturepath);
}

Raylib::Models::ModelB::~ModelB() {
    UnloadTexture(_model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture);
    UnloadModel(_model);
}

Vector3 *Raylib::Models::ModelB::getScale(void)
{
    return (&this->_scale);
}

BoundingBox Raylib::Models::ModelB::getBoundingBox() {
    return GetModelBoundingBox(_model);
}

void Raylib::Models::ModelB::draw(float scale, Color tint) {
    DrawModel(_model, _position, scale, tint);
}

void Raylib::Models::ModelB::drawEx(Vector3 rotationAxis, float rotationAngle) {
    DrawModelEx(_model, _position, rotationAxis, rotationAngle, _scale, WHITE);
}

void Raylib::Models::ModelB::drawWires(float scale, Color tint) {
    DrawModelWires(_model, _position, scale, tint);
}

void Raylib::Models::ModelB::drawWiresEx(Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) {
    DrawModelWiresEx(_model, _position, rotationAxis, rotationAngle, scale, tint);
}

void Raylib::Models::ModelB::drawBoundingBox(Color color) {
    DrawBoundingBox(GetModelBoundingBox(_model), color);
}

void Raylib::Models::ModelB::drawBillboard(Camera camera, Texture2D texture, float size, Color tint) {
    DrawBillboard(camera, texture, _position, size, tint);
}

void Raylib::Models::ModelB::drawBillboardRec(Camera camera, Texture2D texture, Rectangle source, Vector2 size, Color tint) {
    DrawBillboardRec(camera, texture, source, _position, size, tint);
}

void Raylib::Models::ModelB::drawBillboardPro(Camera camera, Texture2D texture, Rectangle source, Vector3 up, Vector2 size, Vector2 origin, float rotation, Color tint) {
    DrawBillboardPro(camera, texture, source, _position, up, size, origin, rotation, tint);
}

void Raylib::Models::ModelB::setTexture(const std::string& path) {
    Texture2D texture = LoadTexture((path + ".png").c_str());

    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

void Raylib::Models::ModelB::setPosition(Vector3 position) {
    _position = position;
}
