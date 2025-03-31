/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** Image.cpp
*/

#include "Image.hpp"

Raylib::Texture::Img::Img(std::string filename)
{
    this->load(filename);
}

Raylib::Texture::Img::~Img(void)
{
    this->unload();
}

Image Raylib::Texture::Img::getImage(void)
{
    return (this->_image);
}

void Raylib::Texture::Img::load(std::string filename)
{
    this->_image = LoadImage(filename.c_str());
}

void Raylib::Texture::Img::loadRaw(std::string filename, int width, int height, int format, int headersize)
{
    this->_image = LoadImageRaw(filename.c_str(), width, height, format, headersize);
}

void Raylib::Texture::Img::loadAnim(std::string filename, int *frames)
{
    this->_image = LoadImageAnim(filename.c_str(), frames);
}

void Raylib::Texture::Img::loadFromMemory(std::string filetype, const unsigned char *filedata, int datasize)
{
    this->_image = LoadImageFromMemory(filetype.c_str(), filedata, datasize);
}

void Raylib::Texture::Img::loadFromTexture(Texture2D texture)
{
    this->_image = LoadImageFromTexture(texture);
}

void Raylib::Texture::Img::loadFromScreen(void)
{
    this->_image = LoadImageFromScreen();
}

void Raylib::Texture::Img::unload(void)
{
    UnloadImage(this->_image);
}

bool Raylib::Texture::Img::exportImg(std::string filename)
{
    return (ExportImage(this->_image, filename.c_str()));
}

bool Raylib::Texture::Img::exportAsCode(std::string filename)
{
    return (ExportImageAsCode(this->_image, filename.c_str()));
}

void Raylib::Texture::Img::genColor(int width, int height, Color color)
{
    this->_image = GenImageColor(width, height, color);
}

void Raylib::Texture::Img::genGradientV(int width, int height, Color top, Color bottom)
{
    this->_image = GenImageGradientV(width, height, top, bottom);
}

void Raylib::Texture::Img::genGradientH(int width, int height, Color left, Color right)
{
    this->_image = GenImageGradientH(width, height, left, right);
}

void Raylib::Texture::Img::genGradientRadial(int width, int height, float density, Color inner, Color outer)
{
    this->_image = GenImageGradientRadial(width, height, density, inner, outer);
}

void Raylib::Texture::Img::genChecked(int width, int height, int checksx, int checksy, Color col1, Color col2)
{
    this->_image = GenImageChecked(width, height, checksx, checksy, col1, col2);
}

void Raylib::Texture::Img::genWhiteNoise(int width, int height, float factor)
{
    this->_image = GenImageWhiteNoise(width, height, factor);
}

void Raylib::Texture::Img::genCellular(int width, int height, int tilesize)
{
    this->_image = GenImageCellular(width, height, tilesize);
}

void Raylib::Texture::Img::copy(Image image)
{
    this->_image = ImageCopy(image);
}

void Raylib::Texture::Img::fromImage(Image image, Rectangle rec)
{
    this->_image = ImageFromImage(image, rec);
}

void Raylib::Texture::Img::fromText(const char *text, int fontSize, Color color)
{
    this->_image = ImageText(text, fontSize, color);
}

void Raylib::Texture::Img::fromTextEx(Font font, const char *text, float fontSize, float spacing, Color tint)
{
    this->_image = ImageTextEx(font, text, fontSize, spacing, tint);
}

void Raylib::Texture::Img::format(int newFormat)
{
    ImageFormat(&this->_image, newFormat);
}

void Raylib::Texture::Img::toPOT(void)
{
    ImageToPOT(&this->_image, *this->_color);
}

void Raylib::Texture::Img::crop(Rectangle crop)
{
    ImageCrop(&this->_image, crop);
}

void Raylib::Texture::Img::alphaCrop(float threshold)
{
    ImageAlphaCrop(&this->_image, threshold);
}

void Raylib::Texture::Img::alphaClear(float threshold)
{
    ImageAlphaClear(&this->_image, *this->_color, threshold);
}

void Raylib::Texture::Img::alphaMask(Image alphaMask)
{
    ImageAlphaMask(&this->_image, alphaMask);
}

void Raylib::Texture::Img::alphaPremultiply(void)
{
    ImageAlphaPremultiply(&this->_image);
}

void Raylib::Texture::Img::resize(int newWidth, int newHeight)
{
    ImageResize(&this->_image, newWidth, newHeight);
}

void Raylib::Texture::Img::resizeNN(int newWidth,int newHeight)
{
    ImageResizeNN(&this->_image, newWidth, newHeight);
}

void Raylib::Texture::Img::resizeCanvas(int newWidth, int newHeight, int offsetX, int offsetY, Color fill)
{
    ImageResize(&this->_image, newWidth, newHeight);
}

void Raylib::Texture::Img::mipmaps(void)
{
    ImageMipmaps(&this->_image);
}

void Raylib::Texture::Img::dither(int rBpp, int gBpp, int bBpp, int aBpp)
{
    ImageDither(&this->_image, rBpp, gBpp, bBpp, aBpp);
}

void Raylib::Texture::Img::flipVertical(void)
{
    ImageFlipVertical(&this->_image);
}

void Raylib::Texture::Img::flipHorizontal(void)
{
    ImageFlipHorizontal(&this->_image);
}

void Raylib::Texture::Img::rotateCW(void)
{
    ImageRotateCW(&this->_image);
}

void Raylib::Texture::Img::rotateCCW(void)
{
    ImageRotateCCW(&this->_image);
}

void Raylib::Texture::Img::colorTint(Color color)
{
    ImageColorTint(&this->_image, color);
}

void Raylib::Texture::Img::colorInvert(void)
{
    ImageColorInvert(&this->_image);
}

void Raylib::Texture::Img::colorGrayscale(void)
{
    ImageColorGrayscale(&this->_image);
}

void Raylib::Texture::Img::colorContrast(float contrast)
{
    ImageColorContrast(&this->_image, contrast);
}

void Raylib::Texture::Img::colorBrightness(int brightness)
{
    ImageColorContrast(&this->_image, brightness);
}

void Raylib::Texture::Img::colorReplace(Color replace)
{
    ImageColorReplace(&this->_image, *this->_color, replace);
}

void Raylib::Texture::Img::loadColors(Image image)
{
    this->_color = LoadImageColors(image);
}

void Raylib::Texture::Img::loadPalette(Image image, int maxPaletteSize, int *colorsCount)
{
    this->_color = LoadImagePalette(image, maxPaletteSize, colorsCount);
}

void Raylib::Texture::Img::unloadColors(void)
{
    UnloadImageColors(this->_color);
}

void Raylib::Texture::Img::unloadPalette(void)
{
    UnloadImagePalette(this->_color);
}

Rectangle Raylib::Texture::Img::getAlphaBorder(float threshold)
{
    return (GetImageAlphaBorder(this->_image, threshold));
}

Color Raylib::Texture::Img::getColor(int x, int y)
{
    return (GetImageColor(this->_image, x, y));
}

void Raylib::Texture::Img::clearBackground(Color color)
{
    ImageClearBackground(&this->_image, color);
}

void Raylib::Texture::Img::drawPixel(int posX, int posY, Color color)
{
    ImageDrawPixel(&this->_image, posX, posY, color);
}

void Raylib::Texture::Img::drawPixelV(Vector2 position, Color color)
{
    ImageDrawPixelV(&this->_image, position, color);
}

void Raylib::Texture::Img::drawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color)
{
    ImageDrawLine(&this->_image, startPosX, startPosY, endPosX, endPosY, color);
}

void Raylib::Texture::Img::drawLineV(Vector2 start, Vector2 end, Color color)
{
    ImageDrawLineV(&this->_image, start, end, color);
}

void Raylib::Texture::Img::drawCircle(int centerX, int centerY, int radius, Color color)
{
    ImageDrawCircle(&this->_image, centerX, centerY, radius, color);
}

void Raylib::Texture::Img::drawCircleV(Vector2 center, int radius, Color color)
{
    ImageDrawCircleV(&this->_image, center, radius, color);
}

void Raylib::Texture::Img::drawRectangle(int posX, int posY, int width, int height, Color color)
{
    ImageDrawRectangle(&this->_image, posX, posY, width, height, color);
}

void Raylib::Texture::Img::drawRectangleV(Vector2 position, Vector2 size, Color color)
{
    ImageDrawRectangleV(&this->_image, position, size, color);
}

void Raylib::Texture::Img::drawRectangleRec(Rectangle rec, Color color)
{
    ImageDrawRectangleRec(&this->_image, rec, color);
}

void Raylib::Texture::Img::drawRectangleLines(Rectangle rec, int thick, Color color)
{
    ImageDrawRectangleLines(&this->_image, rec, thick, color);
}

void Raylib::Texture::Img::draw(Image src, Rectangle srcRec, Rectangle dstRec, Color tint)
{
    ImageDraw(&this->_image, src, srcRec, dstRec, tint);
}

void Raylib::Texture::Img::drawText(const char *text, int posX, int posY, int fontSize, Color color)
{
    ImageDrawText(&this->_image, text, posX, posY, fontSize, color);
}

void Raylib::Texture::Img::drawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint)
{
    ImageDrawTextEx(&this->_image, font, text, position, fontSize, spacing, tint);
}
