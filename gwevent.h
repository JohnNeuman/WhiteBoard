#ifndef GWEVENT_H
#define GWEVENT_H
#include <QMouseEvent>
#include <QGraphicsView>

class gwevent : public QGraphicsView
{
    Q_OBJECT
public:
    gwevent(QWidget *parent);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    ~gwevent();
signals:
    void MousePos(int x, int y);
    void MouseState(QString mouse_state, int x, int y);
    void draw();
};

#endif // GWEVENT_H
