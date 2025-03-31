/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** Texture.hpp
*/

#ifndef INDIESTUDIO_IMAGE_HPP
#define INDIESTUDIO_IMAGE_HPP

#include <iostream>

#include "raylib.h"

namespace Raylib {
    namespace Texture {
        class Img {
            public:
                Image getImage(void);
                void load(std::string filename);
                void loadRaw(std::string filename, int width, int height, int format, int headerSize);
                void loadAnim(std::string filename, int *frames);
                void loadFromMemory(std::string filetype, const unsigned char *filedata, int datasize);
                void loadFromTexture(Texture2D texture);
                void loadFromScreen(void);
                void unload(void);
                bool exportImg(std::string filename);
                bool exportAsCode(std::string filename);
                void genColor(int width, int height, Color color);
                void genGradientV(int width, int height, Color top, Color bottom);
                void genGradientH(int width, int height, Color left, Color right);
                void genGradientRadial(int width, int height, float density, Color inner, Color outer);
                void genChecked(int width, int height, int checksx, int checksy, Color col1, Color col2);
                void genWhiteNoise(int width, int height, float factor);
                void genCellular(int width, int height, int tilesize);
                void copy(Image image);
                void fromImage(Image image, Rectangle rec);
                void fromText(const char *text, int fontSize, Color color);
                void fromTextEx(Font font, const char *text, float fontSize, float spacing, Color tint);
                void format(int newFormat);
                void toPOT(void);
                void crop(Rectangle crop);
                void alphaCrop(float threshold);
                void alphaClear(float threshold);
                void alphaMask(Image alphaMask);
                void alphaPremultiply(void);
                void resize(int newWidth, int newHeight);
                void resizeNN(int newWidth,int newHeight);
                void resizeCanvas(int newWidth, int newHeight, int offsetX, int offsetY, Color fill);
                void mipmaps(void);
                void dither(int rBpp, int gBpp, int bBpp, int aBpp);
                void flipVertical(void);
                void flipHorizontal(void);
                void rotateCW(void);
                void rotateCCW(void);
                void colorTint(Color color);
                void colorInvert(void);
                void colorGrayscale(void);
                void colorContrast(float contrast);
                void colorBrightness(int brightness);
                void colorReplace(Color replace);
                void loadColors(Image image);
                void loadPalette(Image image, int maxPaletteSize, int *colorsCount);
                void unloadColors(void);
                void unloadPalette(void);
                Rectangle getAlphaBorder(float threshold);
                Color getColor(int x, int y);
                void clearBackground(Color color);
                void drawPixel(int posX, int posY, Color color);
                void drawPixelV(Vector2 position, Color color);
                void drawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color);
                void drawLineV(Vector2 start, Vector2 end, Color color);
                void drawCircle(int centerX, int centerY, int radius, Color color);
                void drawCircleV(Vector2 center, int radius, Color color);
                void drawRectangle(int posX, int posY, int width, int height, Color color);
                void drawRectangleV(Vector2 position, Vector2 size, Color color);
                void drawRectangleRec(Rectangle rec, Color color);
                void drawRectangleLines(Rectangle rec, int thick, Color color);
                void draw(Image src, Rectangle srcRec, Rectangle dstRec, Color tint);
                void drawText(const char *text, int posX, int posY, int fontSize, Color color);
                void drawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);
                Img(void) {};
                Img(std::string filename);
                ~Img(void);
            private:
                Image _image;
                Color *_color;
        };
    }
}

#endif
