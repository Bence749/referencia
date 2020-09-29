#ifndef DIGICLOCK_H
#define DIGICLOCK_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class digiClock; }
QT_END_NAMESPACE

class digiClock : public QWidget
{
    Q_OBJECT

public:
    digiClock(QWidget *parent = nullptr);
    ~digiClock();

private:
    Ui::digiClock *ui;
    QTimer _timer;

private slots:
    void showTime();
};
#endif // DIGICLOCK_H
