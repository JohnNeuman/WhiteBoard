#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <state.h>
#include <process.h>
#include <colors.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void changeFigure(QString currFigure);
    void undo();
    void redo();
    void changeColor(QString color);
    void changeWidth(int width);
    void clear();

public:
    Ui::MainWindow *ui;
    Colors *clrs;

private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void on_undo_clicked();
    void on_redo_clicked();
    void on_BlackButton_clicked();
    void on_LightGreyButton_clicked();
    void on_DeepBlueButton_clicked();
    void on_DarkGreenButton_clicked();
    void on_MidGreenButton_clicked();
    void on_HackyButton_clicked();
    void on_DarkRedButton_clicked();
    void on_DarkPinkButton_clicked();
    void on_DarkGreyButton_clicked();
    void on_WhiteButton_clicked();
    void on_MidBlueButton_clicked();
    void on_LightBlueButton_clicked();
    void on_LightGreenButton_clicked();
    void on_YellowButton_clicked();
    void on_RedButton_clicked();
    void on_PinkButton_clicked();
    void on_slider_valueChanged(int value);
    void on_spinBox_valueChanged(int arg1);
    void on_clear_clicked();
};

#endif // MAINWINDOW_H
