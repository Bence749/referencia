#include "form.h"

#include <QApplication>
#include <QLCDNumber>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Form w;
    w.show();
    return a.exec();
}
