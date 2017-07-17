#include "process.h"
#include <QEvent>
#include <figure.h>
#include <QMainWindow>

Process::Process(State *st,QGraphicsView *gw, QMainWindow *window)
{
    this->st = st;
    QObject::connect(this->st->gw,SIGNAL(draw()),this,SLOT(DrawFigure()));
    QObject::connect(window,SIGNAL(undo()),this,SLOT(undo()));
    QObject::connect(window,SIGNAL(redo()),this,SLOT(redo()));
}

void Process::drawLine(int x1, int y1, int x2, int y2, QGraphicsScene *scene)
{
    st->pen = new QPen(QColor(st->clrs->currColor.r,st->clrs->currColor.g,st->clrs->currColor.b));
    st->pen->setWidth(st->width);

    f = new figure();
    f->type = "line";
    f->x1 = x1;
    f->y1 = y1;
    f->x2 = x2;
    f->y2 = y2;
    f->pen = *st->pen;

    line = scene->addLine(x1,y1,x2,y2,*st->pen);
}

void Process::drawCurve(int x1, int y1, int x2, int y2, QGraphicsScene *scene)
{
    st->pen = new QPen(QColor(st->clrs->currColor.r,st->clrs->currColor.g,st->clrs->currColor.b));
    st->pen->setWidth(st->width);
    line = scene->addLine(x1,y1,x2,y2,*st->pen);

    f = new figure();
    f->type = "line";
    f->x1 = x2;
    f->y1 = y2;
    f->x2 = x1;
    f->y2 = y1;
    f->pen = *st->pen;
}

void Process::drawRectangle(int x, int y, int w, int h, QGraphicsScene *scene)
{
    st->pen = new QPen(QColor(st->clrs->currColor.r,st->clrs->currColor.g,st->clrs->currColor.b));
    st->pen->setWidth(st->width);
    if ((w >= x) && (h >= y)) {
        rect = scene->addRect(x,y,w-x,h-y,*st->pen);

        f = new figure();
        f->type = "rect";
        f->x1 = x;
        f->y1 = y;
        f->x2 = w - x;
        f->y2 = h - y;
        f->pen = *st->pen;

    } else if ((w < x) && (h >= y)) {
        rect = scene->addRect(w,y,x-w,h-y,*st->pen);

        f = new figure();
        f->type = "rect";
        f->x1 = w;
        f->y1 = y;
        f->x2 = x - w;
        f->y2 = h - y;
        f->pen = *st->pen;

    } else if ((w >= x) && (h < y)) {
        rect = scene->addRect(x,h,w-x,y-h,*st->pen);

        f = new figure();
        f->type = "rect";
        f->x1 = x;
        f->y1 = h;
        f->x2 = w - x;
        f->y2 = y - h;
        f->pen = *st->pen;

    } else if ((w < x) && (h < y)) {
        rect = scene->addRect(w,h,x-w,y-h,*st->pen);

        f = new figure();
        f->type = "rect";
        f->x1 = w;
        f->y1 = h;
        f->x2 = x - w;
        f->y2 = y - h;
        f->pen = *st->pen;

    }
}

void Process::drawEllipse(int x, int y, int w, int h, QGraphicsScene *scene)
{
    st->pen = new QPen(QColor(st->clrs->currColor.r,st->clrs->currColor.g,st->clrs->currColor.b));
    st->pen->setWidth(st->width);
    ellipse = scene->addEllipse(x,y,w-x,h-y,*st->pen);

    f = new figure();
    f->type = "ellipse";
    f->x1 = x;
    f->y1 = y;
    f->x2 = w - x;
    f->y2 = h - y;
    f->pen = *st->pen;
}

void Process::inc_undo_figures()
{
    for(int i = 0; i < st->undo_figures.size();i++) {
        f = new figure();
        f->scene = st->undo_figures.at(i).scene + 1;
        f->pen = st->undo_figures.at(i).pen;
        f->x1 = st->undo_figures.at(i).x1;
        f->y1 = st->undo_figures.at(i).y1;
        f->x2 = st->undo_figures.at(i).x2;
        f->y2 = st->undo_figures.at(i).y2;
        f->type = st->undo_figures.at(i).type;
        st->undo_figures.removeAt(i);
        st->undo_figures.insert(i,*f);
    }
}

void Process::redrawscene()
{
    if (st->figures.size() > 0) {
        st->scene = new QGraphicsScene(this);
        st->gw->setScene(st->scene);
        int j = 0;
        while (st->figures.at(j).scene < st->scene_num) {
            if (st->figures.at(j).type == "line") {
                st->scene->addLine(st->figures.at(j).x1,st->figures.at(j).y1,st->figures.at(j).x2,st->figures.at(j).y2,st->figures.at(j).pen);
            } else if (st->figures.at(j).type == "rect") {
                st->scene->addRect(st->figures.at(j).x1,st->figures.at(j).y1,st->figures.at(j).x2,st->figures.at(j).y2,st->figures.at(j).pen);
            } else if(st->figures.at(j).type == "ellipse") {
                st->scene->addEllipse(st->figures.at(j).x1,st->figures.at(j).y1,st->figures.at(j).x2,st->figures.at(j).y2,st->figures.at(j).pen);
            }
            j += 1;
        }
        while (st->figures.size() - 1 >= j) {
            st->undo_figures.append(st->figures.at(st->figures.size() - 1));
            st->figures.pop_back();
        }
        st->scene_num -= 1;
    }
}

void Process::redoscene()
{
    int x1,y1,x2,y2;
    if (st->undo_figures.size() > 0) {
        st->scene_num += 1;
        while ((st->undo_figures.size() > 0)&&(st->scene_num == st->undo_figures.at(st->undo_figures.size()-1).scene)) {
            x1 = st->undo_figures.at(st->undo_figures.size()-1).x1;
            y1 = st->undo_figures.at(st->undo_figures.size()-1).y1;
            x2 = st->undo_figures.at(st->undo_figures.size()-1).x2;
            y2 = st->undo_figures.at(st->undo_figures.size()-1).y2;
            if (st->undo_figures.at(st->undo_figures.size()-1).type == "line") {
                st->scene->addLine(x1,y1,x2,y2,st->undo_figures.at(st->undo_figures.size()-1).pen);
            } else if (st->undo_figures.at(st->undo_figures.size()-1).type == "rect") {
                st->scene->addRect(x1,y1,x2,y2,st->undo_figures.at(st->undo_figures.size()-1).pen);
            } else if (st->undo_figures.at(st->undo_figures.size()-1).type == "ellipse") {
                st->scene->addEllipse(x1,y1,x2,y2,st->undo_figures.at(st->undo_figures.size()-1).pen);
            }
            st->figures.append(st->undo_figures.at(st->undo_figures.size() - 1));
            st->undo_figures.pop_back();
        }
    }
}

Process::~Process()
{
    delete[] this->line;
    delete[] this->rect;
    delete[] this->ellipse;
    delete[] this->st;
    delete[] this->f;

}

void Process::DrawFigure()
{
    if (this->st->state == "press") {

        if (!st->newFigure) {
            if (st->currFigure == "Line") {
                this->st->scene->removeItem(line);
                st->figures.pop_back();
            } else if (st->currFigure == "Rectangle") {
                this->st->scene->removeItem(rect);
                st->figures.pop_back();
            } else if (st->currFigure == "Ellipse") {
                this->st->scene->removeItem(ellipse);
                st->figures.pop_back();
            }
        } else {
            st->scene_num += 1;
            inc_undo_figures();
            prev_x = st->x0;
            prev_y = st->y0;
        }
        if (st->currFigure == "Line") {
            drawLine(st->x0,st->y0,st->curr_x,st->curr_y,st->scene);
            st->newFigure = false;
        } else if (st->currFigure == "Rectangle") {
            drawRectangle(st->x0,st->y0,st->curr_x,st->curr_y,st->scene);
            st->newFigure = false;
        } else if (st->currFigure == "Curve") {
            drawCurve(prev_x,prev_y,st->curr_x,st->curr_y,st->scene);
            prev_x = st->curr_x;
            prev_y = st->curr_y;
            st->newFigure = false;
        } else if (st->currFigure == "Ellipse") {
            drawEllipse(st->x0,st->y0,st->curr_x,st->curr_y,st->scene);
            st->newFigure = false;
        }

        f->scene = st->scene_num;
        st->figures.append(*f);
    } else {
        st->newFigure = true;

    }

}

void Process::undo()
{
    redrawscene();
}

void Process::redo()
{
    redoscene();
}
