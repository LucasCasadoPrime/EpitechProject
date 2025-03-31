/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <iostream>
#include "raylib.h"


namespace Raylib {
    namespace Texts {
        class Text {
            public:
                Text(const std::string &text, int posx, int posy, int size, Color color);
                ~Text();
                void FPSDraw();
                void TextDraw();
                void TextDraw(std::string str);
                void TextDrawEx(Font font, Vector2 position, float font_size, float spacing);
                void TextDrawPro(Font font, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing);
                void TextDrawCodepoint(Font font, int codepoint, Vector2 position, float fontSize);
                int TextMeasure(int font_size);
                Vector2 TextMeasureEx(Font font, float fontSize, float spacing);
                int getIndexGlyph(Font font, int codepoint);
                GlyphInfo getGlyphInfo(Font font, int codepoint);
                Rectangle getGlyphRecAtlas(Font font, int codepoint);
                int *CodepointsLoad(int *count);
                void CodepointsUnload(int *codepoints);
                int getCodepointsCount();
                int getCodepoints(int *bytesProcessed);
                std::string getCodepointToUTF8(int codepoint, int *byteSize);
                std::string getTextCodepointsToUTF8(int *codepoint, int length);
                int CopyText(char *dst, const char *src);
                bool TextIsEqual(std::string text1, std::string text2);
                unsigned int TextLen();
                std::string FormatText(...);
                std::string SubTextText(int position, int length);
                std::string ReplaceText(char *text, std::string replace, std::string by);
                std::string InsertText(std::string text, std::string insert, int position);
                std::string TextJoin(const char **textList, int count, std::string delimiter);
                const char **SplitText(std::string text, char delimiter, int *count);
                void AppendText(char *text, std::string append, int *position);
                std::string ToUpper(const char *text);
                int IndexTextFind(std::string text, std::string find);
                std::string ToLower(const char *text);
                std::string ToPascal(const char *text);
                int ToInteger(const char *text);

            private:
                std::string _text;
                int _posX;
                int _posY;
                int _size;
                Color _color;
        };
    }
}

#endif /* !TEXT_HPP_ */
