#ifndef DIGICLOCK2_H
#define DIGICLOCK2_H

#include <QLCDNumber>
#include <QTimer>

class digiclock2 : public QLCDNumber
{
    Q_OBJECT

public:
    digiclock2(QWidget *parent = nullptr);
    ~digiclock2();

private:
    int _timeZone;
    QTimer _timer;

public:
    void setTimeZone(int t) { _timeZone = t; }

private slots:
    void showTime();
};
#endif // DIGICLOCK2_H
