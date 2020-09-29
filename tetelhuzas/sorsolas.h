#ifndef SORSOLAS_H
#define SORSOLAS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class sorsolas; }
QT_END_NAMESPACE

class sorsolas : public QWidget
{
    Q_OBJECT

public:
    sorsolas(QWidget *parent = nullptr);
    ~sorsolas();

private:
    Ui::sorsolas *ui;
    int maxTetel = 24;
    int letszam = 4;
    int aktiv = 0;
    int wasActive = false;
    QList<int> huzott;

private slots:
    void showRandom();
    void showSetting();
    void setInput();
};
#endif // SORSOLAS_H
