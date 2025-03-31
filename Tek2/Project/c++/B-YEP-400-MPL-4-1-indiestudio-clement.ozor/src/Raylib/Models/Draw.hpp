/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Draw.hpp
*/

#ifndef INDIESTUDIO_DRAW_HPP
#define INDIESTUDIO_DRAW_HPP

#include "raylib.h"

namespace Raylib {
    namespace Models {
        class Draw {
            public:
                Draw();
                ~Draw();

                void line3D(Vector3 startPos, Vector3 endPos, Color color);
                void point3D(Vector3 position, Color color);
                void circle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color);
                void triangle3D(Vector3 v1, Vector3 v2, Vector3 v3, Color color);
                void triangleStrip3D(Vector3 *points, int pointsCount, Color color);
                void cube(Vector3 position, float width, float height, float length, Color color);
                void cubeV(Vector3 position, Vector3 size, Color color);
                void cubeWires(Vector3 position, float width, float height, float length, Color color);
                void cubeWiresV(Vector3 position, Vector3 size, Color color);
                void cubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color);
                void cubeTextureRec(Texture2D texture, Rectangle source, Vector3 position, float width, float height, float length, Color color);
                void sphere(Vector3 centerPos, float radius, Color color);
                void sphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color);
                void sphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color);
                void cylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color);
                void cylinderEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color);
                void cylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color);
                void cylinderWiresEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color);
                void plane(Vector3 centerPos, Vector2 size, Color color);
                void ray(Ray ray, Color color);
                void grid(int slices, float spacing);
        };
    }
}

#endif
