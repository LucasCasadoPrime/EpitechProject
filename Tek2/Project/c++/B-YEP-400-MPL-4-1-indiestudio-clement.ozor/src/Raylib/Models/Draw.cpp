/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Draw.cpp
*/

#include "Draw.hpp"

Raylib::Models::Draw::Draw() {}

Raylib::Models::Draw::~Draw() {}

void Raylib::Models::Draw::line3D(Vector3 startPos, Vector3 endPos, Color color) {
    DrawLine3D(startPos, endPos, color);
}

void Raylib::Models::Draw::point3D(Vector3 position, Color color) {
    DrawPoint3D(position, color);
}

void Raylib::Models::Draw::circle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color) {
    DrawCircle3D(center, radius, rotationAxis, rotationAngle, color);
}

void Raylib::Models::Draw::triangle3D(Vector3 v1, Vector3 v2, Vector3 v3, Color color) {
    DrawTriangle3D(v1, v2, v3, color);
}

void Raylib::Models::Draw::triangleStrip3D(Vector3 *points, int pointsCount, Color color) {
    DrawTriangleStrip3D(points, pointsCount, color);
}

void Raylib::Models::Draw::cube(Vector3 position, float width, float height, float length, Color color) {
    DrawCube(position, width, height, length, color);
}

void Raylib::Models::Draw::cubeV(Vector3 position, Vector3 size, Color color) {
    DrawCubeV(position, size, color);
}

void Raylib::Models::Draw::cubeWires(Vector3 position, float width, float height, float length, Color color) {
    DrawCubeWires(position, width, height, length, color);
}

void Raylib::Models::Draw::cubeWiresV(Vector3 position, Vector3 size, Color color) {
    DrawCubeWiresV(position, size, color);
}

void Raylib::Models::Draw::cubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color) {
    DrawCubeTexture(texture, position, width, height, length, color);
}

void Raylib::Models::Draw::cubeTextureRec(Texture2D texture, Rectangle source, Vector3 position, float width, float height, float length, Color color) {
    DrawCubeTextureRec(texture, source, position, width, height, length, color);
}

void Raylib::Models::Draw::sphere(Vector3 centerPos, float radius, Color color) {
    DrawSphere(centerPos, radius, color);
}

void Raylib::Models::Draw::sphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color) {
    DrawSphereEx(centerPos, radius, rings, slices, color);
}

void Raylib::Models::Draw::sphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color) {
    DrawSphereWires(centerPos, radius, rings, slices, color);
}

void Raylib::Models::Draw::cylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) {
    DrawCylinder(position, radiusTop, radiusBottom, height, slices, color);
}

void Raylib::Models::Draw::cylinderEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color) {
    DrawCylinderEx(startPos, endPos, startRadius, endRadius, sides, color);
}

void Raylib::Models::Draw::cylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color) {
    DrawCylinderWires(position, radiusTop, radiusBottom, height, slices, color);
}

void Raylib::Models::Draw::cylinderWiresEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color) {
    DrawCylinderWiresEx(startPos, endPos, startRadius, endRadius, sides, color);
}

void Raylib::Models::Draw::plane(Vector3 centerPos, Vector2 size, Color color) {
    DrawPlane(centerPos, size, color);
}

void Raylib::Models::Draw::ray(Ray ray, Color color) {
    DrawRay(ray, color);
}

void Raylib::Models::Draw::grid(int slices, float spacing) {
    DrawGrid(slices, spacing);
}