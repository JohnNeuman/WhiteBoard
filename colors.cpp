#include "colors.h"

Colors::Colors(QString color)
{
    Black.b = 0;
    Black.g = 0;
    Black.r = 0;

    LightGrey.r = 192;
    LightGrey.b = 192;
    LightGrey.g = 192;

    DeepBlue.b = 128;
    DeepBlue.r = 0;
    DeepBlue.g = 0;

    DarkGreen.b = 0;
    DarkGreen.g = 64;
    DarkGreen.r = 0;

    MidGreen.b = 0;
    MidGreen.g = 128;
    MidGreen.r = 0;

    Hacky.b = 0;
    Hacky.g = 128;
    Hacky.r = 128;

    DarkRed.b = 0;
    DarkRed.g = 0;
    DarkRed.r = 128;

    DarkPink.b = 64;
    DarkPink.g = 0;
    DarkPink.r = 128;

    DarkGrey.b = 128;
    DarkGrey.g = 128;
    DarkGrey.r = 128;

    White.b = 255;
    White.g = 255;
    White.r = 255;

    MidBlue.b = 255;
    MidBlue.g = 0;
    MidBlue.r = 0;

    LightBlue.b = 255;
    LightBlue.g = 255;
    LightBlue.r = 0;

    LightGreen.b = 0;
    LightGreen.g = 255;
    LightGreen.r = 0;

    Yellow.b = 0;
    Yellow.g = 255;
    Yellow.r = 255;

    Red.b = 0;
    Red.g = 0;
    Red.r = 255;

    Pink.b = 255;
    Pink.g = 0;
    Pink.r = 255;

    if (color == "Black") {
        currColor = Black;
    } else if (color == "LightGrey") {
        currColor = LightGrey;
    } else if (color == "DeepBlue") {
        currColor = DeepBlue;
    } else if (color == "DarkGreen") {
        currColor = DarkGreen;
    } else if (color == "MidGreen") {
        currColor = MidGreen;
    } else if (color == "Hacky") {
        currColor = Hacky;
    } else if (color == "DarkRed") {
        currColor = DarkRed;
    } else if (color == "DarkPink") {
        currColor = DarkPink;
    } else if (color == "DarkGrey") {
        currColor = DarkGrey;
    } else if (color == "White") {
        currColor = White;
    } else if (color == "MidBlue") {
        currColor = MidBlue;
    } else if (color == "LightBlue") {
        currColor = LightBlue;
    } else if (color == "LightGreen") {
        currColor = LightGreen;
    } else if (color == "Yellow") {
        currColor = Yellow;
    } else if (color == "Red") {
        currColor = Red;
    } else if (color == "Pink") {
        currColor = Pink;
    }

}

Colors::~Colors()
{

}

void Colors::ChangeCurrColor(QString color)
{
    if (color == "Black") {
        currColor = Black;
    } else if (color == "LightGrey") {
        currColor = LightGrey;
    } else if (color == "DeepBlue") {
        currColor = DeepBlue;
    } else if (color == "DarkGreen") {
        currColor = DarkGreen;
    } else if (color == "MidGreen") {
        currColor = MidGreen;
    } else if (color == "Hacky") {
        currColor = Hacky;
    } else if (color == "DarkRed") {
        currColor = DarkRed;
    } else if (color == "DarkPink") {
        currColor = DarkPink;
    } else if (color == "DarkGrey") {
        currColor = DarkGrey;
    } else if (color == "White") {
        currColor = White;
    } else if (color == "MidBlue") {
        currColor = MidBlue;
    } else if (color == "LightBlue") {
        currColor = LightBlue;
    } else if (color == "LightGreen") {
        currColor = LightGreen;
    } else if (color == "Yellow") {
        currColor = Yellow;
    } else if (color == "Red") {
        currColor = Red;
    } else if (color == "Pink") {
        currColor = Pink;
    }
}
