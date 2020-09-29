#include "quitwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QuitWidget w;
    w.show();
    return a.exec();
}
