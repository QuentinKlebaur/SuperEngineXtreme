#include "Color.hpp"

sex::Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) :
    red{r}, green{g}, blue{b}, alpha{a}
{
}

sex::Color::Color(Color const &color) :
    red{color.red}, green{color.green}, blue{color.blue}, alpha{color.alpha}
{
}
