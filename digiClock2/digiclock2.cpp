#include "digiclock2.h"
#include <QTime>

digiclock2::digiclock2(QWidget *parent)
    : QLCDNumber(parent)
{
    setWindowTitle(tr(""));
    resize(150, 60);
    connect(&_timer, SIGNAL(timeout()), this, SLOT(showTime()));
    _timer.start(1000);
    _timeZone = 0;
}

digiclock2::~digiclock2()
{
}

void digiclock2::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.addSecs(3600 * _timeZone).toString("hh:mm");
    if(time.second() % 2 == 0) text[2] = ' ';
    display(text);
}

