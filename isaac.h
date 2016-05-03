#ifndef ISAAC_H
#define ISAAC_H

#include <QWidget>
#include "keythread.h"

#define bt_back_pin  28
#define bt_next_pin  29
#define bt_add_pin  25
#define bt_minus_pin 27

namespace Ui {
class isaac;
}

class isaac : public QWidget
{
    Q_OBJECT

public:
    explicit isaac(QWidget *parent = 0);
    ~isaac();
    keythread *rpikeythread;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void changeDisplay(QString p);
    void checkDisplay(int index);
    void on_bt_plus_clicked();

    void on_bt_neg_clicked();
    void wgroup(bool en);
    void keylog(int key);
    void update_tm();

    //void on_pushButton_3_clicked();

private:
    Ui::isaac *ui;
    int page=0;
    QString dataArray[11];
    QString p1 =":/iSAACUI1.png";
    QString p2 =":/iSAACUI2.png";
    QString p3 =":/iSAACUI3.png";
    QString p4 =":/iSAACUI4.png";
    QString p5 =":/iSAACUI5.png";
    QString p6 =":/iSAACUI6.png";
    QString p7 =":/iSAACUI7.png";
    QString p8 =":/iSAACUI8.png";
    QString p9 =":/iSAACUI9.png";
    QString p10 =":/iSAACUI10.png";
    QString p11 =":/iSAACUI11.png";

     QTimer *tm;
};

#endif // ISAAC_H
