#ifndef PROCESS_H
#define PROCESS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <figure.h>
#include <state.h>
#include <QMainWindow>

class Process : QGraphicsScene
{
    Q_OBJECT
public:

    QGraphicsLineItem *line;
    QGraphicsRectItem *rect;
    QGraphicsEllipseItem *ellipse;
    State *st;
    figure *f;
    int prev_x,prev_y;
    Process(State *st,QGraphicsView *gw,QMainWindow *window);
    void drawLine(int x1, int y1, int x2, int y2, QGraphicsScene *scene);
    void drawCurve(int x1, int y1, int x2, int y2, QGraphicsScene *scene);
    void drawRectangle(int x, int y, int w, int h, QGraphicsScene *scene);
    void drawEllipse(int x, int y, int w, int h, QGraphicsScene *scene);
    void inc_undo_figures();
    void redrawscene();
    void redoscene();
    ~Process();

private slots:
    void DrawFigure();
    void undo();
    void redo();
};

#endif // PROCESS_H
