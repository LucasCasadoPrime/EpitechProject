/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Material.hpp
*/

#ifndef BOMBERMAN_MATERIAL_HPP
#define BOMBERMAN_MATERIAL_HPP

#include "Essentials.hpp"
#include "raylib.h"

namespace Raylib{
    namespace Models {
        class MaterialB {
            public:
                MaterialB(const std::string &fileName, int *materialCount);
                ~MaterialB();

                Material loadMaterialDefault();
                void setMaterialTexture(int mapType, Texture2D texture);
                void setModelMeshMaterial(Model *model, int meshId, int materialId);

            private:
                Material *_material;
        };
    }
}

#endif //BOMBERMAN_MATERIAL_HPP
