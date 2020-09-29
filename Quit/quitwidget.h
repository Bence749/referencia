#ifndef QUITWIDGET_H
#define QUITWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class QuitWidget; }
QT_END_NAMESPACE

class QuitWidget : public QWidget
{
    Q_OBJECT

public:
    QuitWidget(QWidget *parent = nullptr);
    ~QuitWidget();

private:
    Ui::QuitWidget *ui;

private slots:
    //void quitButton_onClick();
    void on_quitButton_clicked();
};
#endif // QUITWIDGET_H
