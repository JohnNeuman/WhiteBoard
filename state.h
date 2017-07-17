#ifndef STATE_H
#define STATE_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <figure.h>
#include <QMainWindow>
#include <colors.h>

class State : QGraphicsScene
{
    Q_OBJECT
public:
    State(QGraphicsView *gw,QMainWindow *window);
    QGraphicsScene *scene;
    QGraphicsView *gw;
    QList<figure> figures,undo_figures;
    QString state,currFigure;
    int curr_x,curr_y,x0,y0,width,scene_num;
    Colors *clrs;
    bool newFigure;
    QPen *pen;
    ~State();
public slots:
    void MouseState(QString mouse_state,int x, int y);
    void Position(int x, int y);
    void ChangeFigure(QString currFigure);
    void ChangeColor(QString color);
    void ChangeWidth(int width);
    void clear();
};

#endif // STATE_H
