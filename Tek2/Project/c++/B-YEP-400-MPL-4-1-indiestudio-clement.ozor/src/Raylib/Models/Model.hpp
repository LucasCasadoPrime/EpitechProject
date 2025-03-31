/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Model.hpp
*/

#ifndef BOMBERMAN_MODEL_HPP
#define BOMBERMAN_MODEL_HPP

#include "Essentials.hpp"
#include "raylib.h"

//TODO:
//    Model LoadModelFromMesh(Mesh mesh);                                                                // Load model from generated mesh (default material)M)
//    void UnloadModelKeepMeshes(Model model);                                                           // Unload model (but not meshes) from memory (RAM and/or VRAM)

namespace Raylib {
    namespace Models {
        class ModelB
        {
            public:
                ModelB(const std::string &modelpath, const std::string &texturepath, Vector3 position, Vector3 scale);
                ~ModelB();

                BoundingBox getBoundingBox();

                void draw(float scale, Color tint);
                void drawEx(Vector3 rotationAxis, float rotationAngle);
                void drawWires(float scale, Color tint);
                void drawWiresEx(Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);
                void drawBoundingBox(Color color);
                void drawBillboard(Camera camera, Texture2D texture, float size, Color tint);
                void drawBillboardRec(Camera camera, Texture2D texture, Rectangle source, Vector2 size, Color tint);
                void drawBillboardPro(Camera camera, Texture2D texture, Rectangle source, Vector3 up, Vector2 size, Vector2 origin, float rotation, Color tint);
                void setTexture(const std::string& path);
                void setPosition(Vector3 position);
                Vector3 *getScale(void);
            private:
                Model _model;
                std::string _path;
                Vector3 _position;
                Vector3 _scale;
        };
    }
}

#endif