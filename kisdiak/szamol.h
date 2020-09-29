#ifndef SZAMOL_H
#define SZAMOL_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class szamol; }
QT_END_NAMESPACE

class szamol : public QWidget
{
    Q_OBJECT

public:
    szamol(QWidget *parent = nullptr);
    ~szamol();

private:
    Ui::szamol *ui;
    void error();

private slots:
    void changeOp();
    void generate();
    void evaluate();
};
#endif // SZAMOL_H
