#include "digiclock.h"
#include "ui_digiclock.h"
#include <QTime>

digiClock::digiClock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::digiClock)
{
    ui->setupUi(this);
    connect(&_timer, SIGNAL(timeout()), this, SLOT(showTime()));
    _timer.start(1000);
}

digiClock::~digiClock()
{
    delete ui;
}

void digiClock::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if(time.second() % 2 == 0) text[2] = ' ';
    ui->timeBud->display(text);
}

