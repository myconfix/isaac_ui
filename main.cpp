#include "isaac.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    isaac w;
    w.show();

    return a.exec();
}
