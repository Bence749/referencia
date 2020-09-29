#include "buttonhunt.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ButtonHunt w;
    w.show();
    return a.exec();
}
