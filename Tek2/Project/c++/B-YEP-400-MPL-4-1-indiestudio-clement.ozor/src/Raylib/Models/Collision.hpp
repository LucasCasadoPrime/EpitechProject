/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Collision.hpp
*/

#ifndef BOMBERMAN_COLLISION_HPP
#define BOMBERMAN_COLLISION_HPP

#include "raylib.h"

//TODO:
//    Collision detection functions
//    bool CheckCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2);        // Check collision between two spheres
//    bool CheckCollisionBoxes(BoundingBox box1, BoundingBox box2);                                      // Check collision between two bounding boxes
//    bool CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius);                       // Check collision between box and sphere
//    RayCollision GetRayCollisionSphere(Ray ray, Vector3 center, float radius);                         // Get collision info between ray and sphere
//    RayCollision GetRayCollisionBox(Ray ray, BoundingBox box);                                         // Get collision info between ray and box
//    RayCollision GetRayCollisionModel(Ray ray, Model model);                                           // Get collision info between ray and model
//    RayCollision GetRayCollisionMesh(Ray ray, Mesh mesh, Matrix transform);                            // Get collision info between ray and mesh
//    RayCollision GetRayCollisionTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3);                 // Get collision info between ray and triangle
//    RayCollision GetRayCollisionQuad(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4);         // Get collision info between ray and quad

namespace Raylib {
    namespace Models {
        class Collision {
            public:
                Collision();
                ~Collision();

                bool checkCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2);
                bool checkCollisionBoxes(BoundingBox box1, BoundingBox box2);
                bool checkCollisionBoxSphere(BoundingBox box, Vector3 center, float radius);
                RayCollision getRayCollisionSphere(Ray ray, Vector3 center, float radius);
                RayCollision getRayCollisionBox(Ray ray, BoundingBox box);
                RayCollision getRayCollisionModel(Ray ray, Model model);
                RayCollision getRayCollisionMesh(Ray ray, Mesh mesh, Matrix transform);
                RayCollision getRayCollisionTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3);
                RayCollision getRayCollisionQuad(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4);
        };
    }
}

#endif