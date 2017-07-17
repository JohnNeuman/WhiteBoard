#include "state.h"
#include <QGraphicsScene>
#include <gwevent.h>
#include <mainwindow.h>
#include <QMainWindow>

State::State(QGraphicsView *gw, QMainWindow *window)
{  
    this->scene = new QGraphicsScene;
    this->state = "none";
    this->gw = gw;
    this->gw->setScene(scene);
    this->scene_num = 1;
    this->clrs = new Colors("Black");
    this->newFigure = true;

    QObject::connect(gw,SIGNAL(MouseState(QString,int,int)),this,SLOT(MouseState(QString,int,int)));
    QObject::connect(gw,SIGNAL(MousePos(int,int)),this,SLOT(Position(int,int)));
    QObject::connect(window,SIGNAL(changeFigure(QString)),this,SLOT(ChangeFigure(QString)));
    QObject::connect(window,SIGNAL(changeColor(QString)),this,SLOT(ChangeColor(QString)));
    QObject::connect(window,SIGNAL(changeWidth(int)),this,SLOT(ChangeWidth(int)));
    QObject::connect(window,SIGNAL(clear()),this,SLOT(clear()));
}

State::~State()
{
    delete[] scene;
    delete[] gw;
    delete[] clrs;
    delete[] pen;
}

void State::MouseState(QString mouse_state,int x, int y)
{
    if (mouse_state == "press") {
        this->state = "press";
        this->x0 = x;
        this->y0 = y;
    }
    else if (mouse_state == "release") {
        this->state = "release";
        this->x0 = 0;
        this->y0 = 0;
        newFigure = true;
    }
}

void State::Position(int x, int y)
{
    if (this->state == "press") {
        this->curr_x = x;
        this->curr_y = y;
    }
}

void State::ChangeFigure(QString currFigure)
{
    this->currFigure = currFigure;
}

void State::ChangeColor(QString color)
{
    this->clrs->ChangeCurrColor(color);
}

void State::ChangeWidth(int width)
{
    this->width = width;
}

void State::clear()
{
    this->scene = new QGraphicsScene;
    this->gw->setScene(this->scene);
    this->figures.clear();
    this->undo_figures.clear();
    this->scene_num = 1;
}


