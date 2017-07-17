#ifndef COLORS_H
#define COLORS_H
#include <QString>

class Colors
{
public:
    Colors(QString color);
    ~Colors();
    struct Color{
        int r;
        int g;
        int b;
    } Black,LightGrey,DeepBlue,DarkGreen,MidGreen,Hacky,DarkRed,DarkPink,DarkGrey,White,MidBlue,LightBlue,LightGreen,Yellow,Red,Pink,CurrColor;
    Color currColor;
    void ChangeCurrColor(QString color);
};

#endif // COLORS_H
