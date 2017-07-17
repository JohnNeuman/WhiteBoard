#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <state.h>
#include <process.h>
#include <QGraphicsScene>
#include <colors.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->comboBox->addItem("Line");
    ui->comboBox->addItem("Curve");
    ui->comboBox->addItem("Rectangle");
    ui->comboBox->addItem("Ellipse");

    clrs = new Colors("Black");

    ui->slider->setRange(1,10);
    ui->spinBox->setRange(1,10);

    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->Black.r).arg(clrs->Black.g).arg(clrs->Black.b));

    ui->BlackButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->Black.r).arg(clrs->Black.g).arg(clrs->Black.b));
    ui->LightGreyButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->LightGrey.r).arg(clrs->LightGrey.g).arg(clrs->LightGrey.b));
    ui->DeepBlueButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->DeepBlue.r).arg(clrs->DeepBlue.g).arg(clrs->DeepBlue.b));
    ui->DarkGreenButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->DarkGreen.r).arg(clrs->DarkGreen.g).arg(clrs->DarkGreen.b));
    ui->MidGreenButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->MidGreen.r).arg(clrs->MidGreen.g).arg(clrs->MidGreen.b));
    ui->HackyButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->Hacky.r).arg(clrs->Hacky.g).arg(clrs->Hacky.b));
    ui->DarkRedButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->DarkRed.r).arg(clrs->DarkRed.g).arg(clrs->DarkRed.b));
    ui->DarkPinkButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->DarkPink.r).arg(clrs->DarkPink.g).arg(clrs->DarkPink.b));
    ui->DarkGreyButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->DarkGrey.r).arg(clrs->DarkGrey.g).arg(clrs->DarkGrey.b));
    ui->WhiteButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->White.r).arg(clrs->White.g).arg(clrs->White.b));
    ui->MidBlueButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->MidBlue.r).arg(clrs->MidBlue.g).arg(clrs->MidBlue.b));
    ui->LightBlueButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->LightBlue.r).arg(clrs->LightBlue.g).arg(clrs->LightBlue.b));
    ui->LightGreenButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->LightGreen.r).arg(clrs->LightGreen.g).arg(clrs->LightGreen.b));
    ui->YellowButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->Yellow.r).arg(clrs->Yellow.g).arg(clrs->Yellow.b));
    ui->RedButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->Red.r).arg(clrs->Red.g).arg(clrs->Red.b));
    ui->PinkButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->Pink.r).arg(clrs->Pink.g).arg(clrs->Pink.b));

    State *st;
    Process *pr;

    st = new State(ui->gw, this);
    st->currFigure = "Line";
    st->width = 1;

    pr = new Process(st,ui->gw,this);

    // ui->gw->setScene(st->scene);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    emit(changeFigure(arg1));
    //this->st->currFigure;
}

void MainWindow::on_undo_clicked()
{
    emit undo();
}

void MainWindow::on_redo_clicked()
{
    emit redo();
}

void MainWindow::on_BlackButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->Black.r).arg(clrs->Black.g).arg(clrs->Black.b));
    emit changeColor("Black");
}

void MainWindow::on_LightGreyButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->LightGrey.r).arg(clrs->LightGrey.g).arg(clrs->LightGrey.b));
    emit changeColor("LightGrey");
}

void MainWindow::on_DeepBlueButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->DeepBlue.r).arg(clrs->DeepBlue.g).arg(clrs->DeepBlue.b));
    emit changeColor("DeepBlue");
}

void MainWindow::on_DarkGreenButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->DarkGreen.r).arg(clrs->DarkGreen.g).arg(clrs->DarkGreen.b));
    emit changeColor("DarkGreen");
}

void MainWindow::on_MidGreenButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->MidGreen.r).arg(clrs->MidGreen.g).arg(clrs->MidGreen.b));
    emit changeColor("MidGreen");
}

void MainWindow::on_HackyButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->Hacky.r).arg(clrs->Hacky.g).arg(clrs->Hacky.b));
    emit changeColor("Hacky");
}

void MainWindow::on_DarkRedButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->DarkRed.r).arg(clrs->DarkRed.g).arg(clrs->DarkRed.b));
    emit changeColor("DarkRed");
}

void MainWindow::on_DarkPinkButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->DarkPink.r).arg(clrs->DarkPink.g).arg(clrs->DarkPink.b));
    emit changeColor("DarkPink");
}

void MainWindow::on_DarkGreyButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->DarkGrey.r).arg(clrs->DarkGrey.g).arg(clrs->DarkGrey.b));
    emit changeColor("DarkGrey");
}

void MainWindow::on_WhiteButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->White.r).arg(clrs->White.g).arg(clrs->White.b));
    emit changeColor("White");
}

void MainWindow::on_MidBlueButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->MidBlue.r).arg(clrs->MidBlue.g).arg(clrs->MidBlue.b));
    emit changeColor("MidBlue");
}

void MainWindow::on_LightBlueButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->LightBlue.r).arg(clrs->LightBlue.g).arg(clrs->LightBlue.b));
    emit changeColor("LightBlue");
}

void MainWindow::on_LightGreenButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->LightGreen.r).arg(clrs->LightGreen.g).arg(clrs->LightGreen.b));
    emit changeColor("LightGreen");
}

void MainWindow::on_YellowButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->Yellow.r).arg(clrs->Yellow.g).arg(clrs->Yellow.b));
    emit changeColor("Yellow");
}

void MainWindow::on_RedButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->Red.r).arg(clrs->Red.g).arg(clrs->Red.b));
    emit changeColor("Red");
}

void MainWindow::on_PinkButton_clicked()
{
    ui->ColorButton->setStyleSheet(QString("border: 0px; background:rgb(%1,%2,%3)").arg(clrs->Pink.r).arg(clrs->Pink.g).arg(clrs->Pink.b));
    emit changeColor("Pink");
}

void MainWindow::on_slider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    emit changeWidth(value);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->slider->setValue(arg1);
    emit changeWidth(arg1);
}

void MainWindow::on_clear_clicked()
{
    emit clear();
}
