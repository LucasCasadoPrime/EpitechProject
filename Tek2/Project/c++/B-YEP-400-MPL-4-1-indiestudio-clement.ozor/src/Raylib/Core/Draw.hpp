/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Draw.hpp
*/

#ifndef BOMBERMAN_DRAW_HPP
#define BOMBERMAN_DRAW_HPP

#include "raylib.h"

namespace Raylib {
    namespace Core {
        class Draw {
            public:
                Draw();
                ~Draw();

                void clearBackground(Color color);
                void begin();
                void end();
                void beginMode2D(Camera2D camera);
                void endMode2D();
                void beginMode3D(Camera3D camera);
                void endMode3D();
                void beginTextureMode(RenderTexture2D target);
                void endTextureMode();
                void beginShaderMode(Shader shader);
                void endShaderMode();
                void beginBlendMode(int mode);
                void endBlendMode();
                void beginScissorMode(int x, int y, int width, int height);
                void endScissorMode();
                void beginVrStereoMode(VrStereoConfig config);
                void endVrStereoMode();
        };
    }
}

#endif
