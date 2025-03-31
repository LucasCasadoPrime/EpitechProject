/*
** EPITECH PROJECT, 2022
** src/Raylib/Textures/Texture
** File description:
** Texture.cpp
*/

#ifndef INDIESTUDIO_TEXTURE_HPP
#define INDIESTUDIO_TEXTURE_HPP

#include "raylib.h"

namespace Raylib {
    namespace Texture {
        class Tex {
            public:
                void load(const char *fileName);
                void loadFromImage(Image image);
                void loadCubemap(Image image, int layout);
                void loadRender(int width, int height);
                void unload(void);
                void unloadRender(void);
                void update(const void *pixels);
                void updateRec(Rectangle rec, const void *pixels);
                void genMipmaps(void);
                void setFilter(int filter);
                void setWrap(int wrap);
                void draw(int posX, int posY, Color tint);
                void drawV(Vector2 position, Color tint);
                void drawEx(Vector2 position, float rotation, float scale, Color tint);
                void drawRec(Rectangle source, Vector2 position, Color tint);
                void drawQuad(Vector2 tiling, Vector2 offset, Rectangle quad, Color tint);
                void drawTiled(Rectangle source, Rectangle dest, Vector2 origin, float rotation, float scale, Color tint);
                void drawPro(Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint);
                void drawNPatch(NPatchInfo npatchinfo, Rectangle dest, Vector2 origin, float rotation, Color tint);
                void drawPoly(Vector2 center, Vector2 *points, Vector2 *texcoords, int pointscount, Color tint);
                void fade(float alpha);
                int colorToInt(void);
                Vector4 colorNormalize(void);
                void colorFromNormalized(Vector4 normalized);
                Vector3 colorToHSV(void);
                void colorFromHSV(float hue, float saturation, float value);
                void colorAlpha(float alpha);
                void colorAlphaBlend(Color src, Color tint);
                Color getColor(unsigned int hexValue);
                Color getPixelColor(int format);
                void setPixelColor(Color color, int format);
                int getPixelDataSize(int width, int height, int format);
                Tex(void) {};
                Tex(Image image);
                ~Tex(void) {};
            private:
                Texture2D _texture2d;
                TextureCubemap _textureCubemap;
                RenderTexture2D _renderTexture;
                Color _color;
        };
    }
}

#endif