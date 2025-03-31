/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** Text
*/

#include "Text.hpp"

Raylib::Texts::Text::Text(const std::string &text, int posx, int posy, int size, Color color)
{
    _text = text;
    _posX = posx;
    _posY = posy;
    _size = size;
    _color = color;
}

Raylib::Texts::Text::~Text()
{
}

// Text drawing functions

void Raylib::Texts::Text::FPSDraw()
{
    return(DrawFPS(_posX, _posY));
}

void Raylib::Texts::Text::TextDraw()
{
    return(DrawText(_text.c_str(), _posX, _posY, _size, _color));
}

void Raylib::Texts::Text::TextDraw(std::string str)
{
    return(DrawText(str.c_str(), _posX, _posY, _size, _color));
}

void Raylib::Texts::Text::TextDrawEx(Font font, Vector2 position, float font_size, float spacing)
{
    return(DrawTextEx(font, _text.c_str(), position, font_size, spacing, _color));
}

void Raylib::Texts::Text::TextDrawPro(Font font, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing)
{
    return(DrawTextPro(font, _text.c_str(), position, origin, rotation, fontSize, spacing, _color));
}

void Raylib::Texts::Text::TextDrawCodepoint(Font font, int codepoint, Vector2 position, float fontSize)
{
    return(DrawTextCodepoint(font, codepoint, position, fontSize, _color));
}

// Text misc. functions

int Raylib::Texts::Text::TextMeasure(int font_size)
{
    return(MeasureText(_text.c_str(), font_size));
}

Vector2 Raylib::Texts::Text::TextMeasureEx(Font font, float fontSize, float spacing)
{
    return(MeasureTextEx(font, _text.c_str(), fontSize, spacing));
}

int Raylib::Texts::Text::getIndexGlyph(Font font, int codepoint)
{
    return(GetGlyphIndex(font, codepoint));
}

GlyphInfo Raylib::Texts::Text::getGlyphInfo(Font font, int codepoint)
{
    return(GetGlyphInfo(font, codepoint));
}

Rectangle Raylib::Texts::Text::getGlyphRecAtlas(Font font, int codepoint)
{
    return(GetGlyphAtlasRec(font, codepoint));
}

// Text codepoints management functions (unicode characters)

int *Raylib::Texts::Text::CodepointsLoad(int *count)
{
    return(LoadCodepoints(_text.c_str(), count));
}

void Raylib::Texts::Text::CodepointsUnload(int *codepoints)
{
    return(UnloadCodepoints(codepoints));
}

int Raylib::Texts::Text::getCodepointsCount()
{
    return(GetCodepointCount(_text.c_str()));
}

int Raylib::Texts::Text::getCodepoints(int *bytesProcessed)
{
    return(GetCodepoint(_text.c_str(), bytesProcessed));
}

std::string Raylib::Texts::Text::getCodepointToUTF8(int codepoint, int *byteSize)
{
    return(CodepointToUTF8(codepoint, byteSize));
}

std::string Raylib::Texts::Text::getTextCodepointsToUTF8(int *codepoint, int length)
{
    return(TextCodepointsToUTF8(codepoint, length));
}

// Text strings management functions (no utf8 strings, only byte chars)

int Raylib::Texts::Text::CopyText(char *dst, const char *src)
{
    return(TextCopy(dst, src));
}

bool Raylib::Texts::Text::TextIsEqual(std::string text1, std::string text2)
{
    return(TextIsEqual(text1.c_str(), text2.c_str()));
}

unsigned int Raylib::Texts::Text::TextLen()
{
    return(TextLength(_text.c_str()));
}

std::string Raylib::Texts::Text::FormatText(...)
{
    return(TextFormat(_text.c_str()));
}

std::string Raylib::Texts::Text::SubTextText(int position, int length)
{
    return(TextSubtext(_text.c_str(), position, length));
}

std::string Raylib::Texts::Text::ReplaceText(char *text, std::string replace, std::string by)
{
    return(TextReplace(text, replace.c_str(), by.c_str()));
}

std::string Raylib::Texts::Text::InsertText(std::string text, std::string insert, int position)
{
    return(TextInsert(text.c_str(), insert.c_str(), position));
}

std::string Raylib::Texts::Text::TextJoin(const char **textList, int count, std::string delimiter)
{
    return(TextJoin(textList, count, delimiter.c_str()));
}

const char **Raylib::Texts::Text::SplitText(std::string text, char delimiter, int *count)
{
    return(TextSplit(text.c_str(), delimiter, count));
}

void Raylib::Texts::Text::AppendText(char *text, std::string append, int *position)
{
    return(TextAppend(text, append.c_str(), position));
}

int Raylib::Texts::Text::IndexTextFind(std::string text, std::string find)
{
    return(TextFindIndex(text.c_str(), find.c_str()));
}

std::string Raylib::Texts::Text::ToUpper(const char *text)
{
    return(TextToUpper(text));
}

std::string Raylib::Texts::Text::ToLower(const char *text)
{
    return(TextToLower(text));
}

std::string Raylib::Texts::Text::ToPascal(const char *text)
{
    return(TextToPascal(text));
}

int Raylib::Texts::Text::ToInteger(const char *text)
{
    return(TextToInteger(text));
}