/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** Font
*/

#ifndef FfONT_HPP_
#define FfONT_HPP_

#include <iostream>
#include "raylib.h"

namespace Raylib {
    namespace Texts {
        class Ffont {
            public:
                Ffont();
                ~Ffont();
                Font getDefaultFont(void);
                Font fontLoad(std::string filename);
                Font fontLoadEx(std::string filename, int font_size, int *font_chars, int glyph_count);
                Font fontLoadFromFile(Image image, Color key, int firstChar);
                Font fontLoadFromMemory(std::string filetype, const unsigned char *filedata, int datasize, int fontSize, int *fontChars, int glyphCount);
                GlyphInfo *fontLoadData(const unsigned char *filedata, int datasize, int fontSize, int *fontChars, int glyphCount, int type);
                Image genImageAtlasFont(const GlyphInfo *chars, Rectangle **rec, int glyphCount, int fontSize, int padding, int packMethod);
                void unloadDataFont(GlyphInfo *chars, int glyphCount);
                void unloadFont(Font font);
            protected:
            private:
                Font _font;
                GlyphInfo *_glyphInfo;
        };
    }
}

#endif /* !FfONT_HPP_ */
