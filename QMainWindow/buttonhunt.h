#ifndef BUTTONHUNT_H
#define BUTTONHUNT_H

#include <QMainWindow>
#include "QTime"
#include "QTimer"

QT_BEGIN_NAMESPACE
namespace Ui { class ButtonHunt; }
QT_END_NAMESPACE

class ButtonHunt : public QMainWindow
{
    Q_OBJECT

public:
    ButtonHunt(QWidget *parent = nullptr);
    ~ButtonHunt() override;

private:
    Ui::ButtonHunt *ui;
    int points;
    QTime _time;
    QTimer _timer;
    void closeEvent(QCloseEvent *) override;

private slots:
    void pushButton_onClick();
    void updateStatusBar();
    void startButton_onClick();
};
#endif // BUTTONHUNT_H
