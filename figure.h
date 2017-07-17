#ifndef FIGURE_H
#define FIGURE_H
#include <QPen>

class figure
{
public:
    figure();
    QString type;
    int x1,y1,x2,y2,scene,width;
    QPen pen;
};

#endif // FIGURE_H
