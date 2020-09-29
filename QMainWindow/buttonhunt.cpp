#include "buttonhunt.h"
#include "ui_buttonhunt.h"
#include "QTime"
#include "QTimer"
#include "QMessageBox"

ButtonHunt::ButtonHunt(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ButtonHunt)
{
    qsrand(unsigned(QTime::currentTime().msec()));
    points = 0;
    ui->setupUi(this);
    ui->pushButton->setVisible(false);
    ui->statusbar->setVisible(false);
    ui->statusbar->showMessage("Points: " + QString::number(points)
                               + " | Elapsed time: " + QString::number(_time.elapsed()/1000) + " sec");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pushButton_onClick()));
    connect(&_timer, SIGNAL(timeout()), this, SLOT(updateStatusBar()));
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startButton_onClick()));
}

ButtonHunt::~ButtonHunt()
{
    delete ui;
}

void ButtonHunt::pushButton_onClick()
{
    int w = ui->pushButton->width();
    int h = ui->pushButton->height();
    int x = ui->centralwidget->width() - w;
    int y = ui-> centralwidget->height() - h;
    ui->pushButton->setGeometry(qrand() % x, qrand() % y, w, h);
    ++points;
    ui->statusbar->showMessage("Points: " + QString::number(points)
                               + " | Elapsed time: " + QString::number(_time.elapsed()/1000) + " sec");
}

void ButtonHunt::updateStatusBar()
{
    ui->statusbar->showMessage("Points: " + QString::number(points)
                               + " | Elapsed time: " + QString::number(_time.elapsed()/1000) + " sec");
}

void ButtonHunt::closeEvent(QCloseEvent *)
{
    int millisec = _time.elapsed();
    QMessageBox msgBox;
    ui->startButton->isVisible() ? msgBox.setText("The game has not started yet!") :
                                   msgBox.setText("Pushes per second: " + QString::number(double(points)*1000/millisec, 'f', 2));
    msgBox.exec();

}

void ButtonHunt::startButton_onClick()
{
    ui->centralwidget->setMinimumSize(500, 400);
    ui->pushButton->setVisible(true);
    ui->startButton->setVisible(false);
    ui->statusbar->setVisible(true);
    int w = ui->pushButton->width();
    int h = ui->pushButton->height();
    int x = ui->centralwidget->width() - w;
    int y = ui-> centralwidget->height() - h;
    ui->pushButton->setGeometry(qrand() % x, qrand() % y, w, h);
    _time.start();
    _timer.start(1000);
}

