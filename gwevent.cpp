#include "gwevent.h"
#include <QMouseEvent>

gwevent::gwevent(QWidget *parent) : QGraphicsView(parent)
{

}

void gwevent::mouseMoveEvent(QMouseEvent *event) {
    emit MousePos(event->x(),event->y());
    emit draw();
}

void gwevent::mousePressEvent(QMouseEvent *event) {
    emit MouseState("press",event->x(),event->y());
}

void gwevent::mouseReleaseEvent(QMouseEvent *event) {
    emit MouseState("release",event->x(),event->y());
}

gwevent::~gwevent()
{

}
