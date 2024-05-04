#pragma once

namespace sex {
    struct Color
    {
        Color(unsigned char red=0, unsigned char green=0, unsigned char blue=0, unsigned char alpha=255);
        Color(Color const &color);
        Color(Color &&color) = default;
        ~Color() = default;

        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char alpha;
    };
}