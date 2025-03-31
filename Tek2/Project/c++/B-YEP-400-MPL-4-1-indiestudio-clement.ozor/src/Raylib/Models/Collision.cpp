/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Collision.cpp
*/

#include "Collision.hpp"

Raylib::Models::Collision::Collision() {}

Raylib::Models::Collision::~Collision() {}

bool Raylib::Models::Collision::checkCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2) {
    return CheckCollisionSpheres(center1, radius1, center2, radius2);
}

bool Raylib::Models::Collision::checkCollisionBoxes(BoundingBox box1, BoundingBox box2) {
    return CheckCollisionBoxes(box1, box2);
}

bool Raylib::Models::Collision::checkCollisionBoxSphere(BoundingBox box, Vector3 center, float radius) {
    return CheckCollisionBoxSphere(box, center, radius);
}

RayCollision Raylib::Models::Collision::getRayCollisionSphere(Ray ray, Vector3 center, float radius) {
    return GetRayCollisionSphere(ray, center, radius);
}

RayCollision Raylib::Models::Collision::getRayCollisionBox(Ray ray, BoundingBox box) {
    return GetRayCollisionBox(ray, box);
}

RayCollision Raylib::Models::Collision::getRayCollisionModel(Ray ray, Model model) {
    return GetRayCollisionModel(ray, model);
}

RayCollision Raylib::Models::Collision::getRayCollisionMesh(Ray ray, Mesh mesh, Matrix transform) {
    return GetRayCollisionMesh(ray, mesh, transform);
}

RayCollision Raylib::Models::Collision::getRayCollisionTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3) {
    return GetRayCollisionTriangle(ray, p1, p2, p3);
}

RayCollision Raylib::Models::Collision::getRayCollisionQuad(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4) {
    return GetRayCollisionQuad(ray, p1, p2, p3, p4);
}