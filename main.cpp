#include "isaac.h"
#include <QApplication>
#include "wiringPi.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    isaac w;
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();

    //initail wiring pi
    wiringPiSetup();
    pinMode(bt_back_pin,INPUT);
    pinMode(bt_next_pin,INPUT);
    pinMode(bt_add_pin,INPUT);
    pinMode(bt_minus_pin,INPUT);


    return a.exec();
}
