/*
** EPITECH PROJECT, 2022
** src/Raylib/Textures/Texture
** File description:
** Texture.cpp
*/

#include "Texture.hpp"

Raylib::Texture::Tex::Tex(Image image)
{
    this->loadFromImage(image);
}

void Raylib::Texture::Tex::load(const char *filename)
{
    this->_texture2d = LoadTexture(filename);
}

void Raylib::Texture::Tex::loadFromImage(Image image)
{
    this->_texture2d = LoadTextureFromImage(image);
}

void Raylib::Texture::Tex::loadCubemap(Image image, int layout)
{
    this->_textureCubemap = LoadTextureCubemap(image, layout);
}

void Raylib::Texture::Tex::loadRender(int width, int height)
{
    this->_renderTexture = LoadRenderTexture(width, height);
}

void Raylib::Texture::Tex::unload(void)
{
    UnloadTexture(this->_texture2d);
}

void Raylib::Texture::Tex::unloadRender(void)
{
    UnloadRenderTexture(this->_renderTexture);
}

void Raylib::Texture::Tex::update(const void *pixels)
{
    UpdateTexture(this->_texture2d, pixels);
}

void Raylib::Texture::Tex::updateRec(Rectangle rec, const void *pixels)
{
    UpdateTextureRec(this->_texture2d, rec, pixels);
}

void Raylib::Texture::Tex::genMipmaps(void)
{
    GenTextureMipmaps(&this->_texture2d);
}

void Raylib::Texture::Tex::setFilter(int filter)
{
    SetTextureFilter(this->_texture2d, filter);
}

void Raylib::Texture::Tex::setWrap(int wrap)
{
    SetTextureWrap(this->_texture2d, wrap);
}

void Raylib::Texture::Tex::draw(int posX, int posY, Color tint)
{
    DrawTexture(this->_texture2d, posX, posY, tint);
}

void Raylib::Texture::Tex::drawV(Vector2 position, Color tint)
{
    DrawTextureV(this->_texture2d, position, tint);
}

void Raylib::Texture::Tex::drawEx(Vector2 position, float rotation, float scale, Color tint)
{
    DrawTextureEx(this->_texture2d, position, rotation, scale, tint);
}

void Raylib::Texture::Tex::drawRec(Rectangle source, Vector2 position, Color tint)
{
    DrawTextureRec(this->_texture2d, source, position, tint);
}

void Raylib::Texture::Tex::drawQuad(Vector2 tiling, Vector2 offset, Rectangle quad, Color tint)
{
    DrawTextureQuad(this->_texture2d, tiling, offset, quad, tint);
}

void Raylib::Texture::Tex::drawTiled(Rectangle source, Rectangle dest, Vector2 origin, float rotation, float scale, Color tint)
{
    DrawTextureTiled(this->_texture2d, source, dest, origin, rotation, scale, tint);
}

void Raylib::Texture::Tex::drawPro(Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint)
{
    DrawTexturePro(this->_texture2d, source, dest, origin, rotation, tint);
}

void Raylib::Texture::Tex::drawNPatch(NPatchInfo npatchinfo, Rectangle dest, Vector2 origin, float rotation, Color tint)
{
    DrawTextureNPatch(this->_texture2d, npatchinfo, dest, origin, rotation, tint);
}

void Raylib::Texture::Tex::drawPoly(Vector2 center, Vector2 *points, Vector2 *texcoords, int pointscount, Color tint)
{
    DrawTexturePoly(this->_texture2d, center, points, texcoords, pointscount, tint);
}

void Raylib::Texture::Tex::fade(float alpha)
{
    Fade(this->_color, alpha);
}

int Raylib::Texture::Tex::colorToInt(void)
{
    return (ColorToInt(this->_color));
}

Vector4 Raylib::Texture::Tex::colorNormalize(void)
{
    return (ColorNormalize(this->_color));
}

void Raylib::Texture::Tex::colorFromNormalized(Vector4 normalized)
{
    this->_color = ColorFromNormalized(normalized);
}

Vector3 Raylib::Texture::Tex::colorToHSV(void)
{
    return (ColorToHSV(this->_color));
}

void Raylib::Texture::Tex::colorFromHSV(float hue, float saturation, float value)
{
    this->_color = ColorFromHSV(hue, saturation, value);
}

void Raylib::Texture::Tex::colorAlpha(float alpha)
{
    this->_color = ColorAlpha(this->_color, alpha);
}

void Raylib::Texture::Tex::colorAlphaBlend(Color src, Color tint)
{
    ColorAlphaBlend(this->_color, src, tint);
}

Color Raylib::Texture::Tex::getColor(unsigned int hexValue)
{
    return (GetColor(hexValue));
}

Color Raylib::Texture::Tex::getPixelColor(int format)
{
    return (GetPixelColor(&this->_color, format));
}

void Raylib::Texture::Tex::setPixelColor(Color color, int format)
{
    SetPixelColor(&this->_color, color, format);
}

int Raylib::Texture::Tex::getPixelDataSize(int width, int height, int format)
{
    return (GetPixelDataSize(width, height, format));
}