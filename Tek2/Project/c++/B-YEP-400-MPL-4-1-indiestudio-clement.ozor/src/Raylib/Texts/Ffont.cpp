/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** Ffont
*/

#include "Ffont.hpp"

Raylib::Texts::Ffont::Ffont()
{
}

Raylib::Texts::Ffont::~Ffont()
{
}

Font Raylib::Texts::Ffont::getDefaultFont(void)
{
    return(this->_font = GetFontDefault());
}

Font Raylib::Texts::Ffont::fontLoad(std::string filename)
{
    return(this->_font = LoadFont(filename.c_str()));
}

Font Raylib::Texts::Ffont::fontLoadEx(std::string filename, int font_size, int *font_chars, int glyph_count)
{
    return(this->_font = LoadFontEx(filename.c_str(), font_size, font_chars, glyph_count));
}

Font Raylib::Texts::Ffont::fontLoadFromFile(Image image, Color key, int firstChar)
{
    return(this->_font = LoadFontFromImage(image, key, firstChar));
}

Font Raylib::Texts::Ffont::fontLoadFromMemory(std::string filetype, const unsigned char *filedata, int datasize, int fontSize, int *fontChars, int glyphCount)
{
    return(this->_font = LoadFontFromMemory(filetype.c_str(), filedata, datasize, fontSize, fontChars, glyphCount));
}

GlyphInfo *Raylib::Texts::Ffont::fontLoadData(const unsigned char *filedata, int datasize, int fontSize, int *fontChars, int glyphCount, int type)
{
    return(this->_glyphInfo = LoadFontData(filedata, datasize, fontSize, fontChars, glyphCount, type));
}

Image Raylib::Texts::Ffont::genImageAtlasFont(const GlyphInfo *chars, Rectangle **rec, int glyphCount, int fontSize, int padding, int packMethod)
{
    return(GenImageFontAtlas(chars, rec, glyphCount, fontSize, padding, packMethod));
}

void Raylib::Texts::Ffont::unloadDataFont(GlyphInfo *chars, int glyphCount)
{
    UnloadFontData(chars, glyphCount);
}

void Raylib::Texts::Ffont::unloadFont(Font font)
{
    UnloadFont(font);
}