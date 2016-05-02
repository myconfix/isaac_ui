#include "isaac.h"
#include "ui_isaac.h"
#include "QDebug"
#include "wiringPi.h"
#include "keythread.h"

isaac::isaac(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::isaac)
{

    ui->setupUi(this);
    QPixmap mypix(p1);
    ui->lb_background->setPixmap(mypix);
    checkDisplay(0);
    wgroup(false);
    ui->pb_transmit->setVisible(false);

}

isaac::~isaac()
{
    delete ui;
}

void isaac::on_pushButton_clicked()
{
    page++;

    qDebug() << page;
    dataArray[page-1]=ui->lb_value->text();
    ui->lb_value->setText("0");
    qDebug() << "dataArray[" << page-1 <<"] = " <<dataArray[page-1];

        checkDisplay(page);
}

void isaac::on_pushButton_2_clicked()
{
    page--;
    if(page<0)
        page =0;
    checkDisplay(page);
    ui->lb_value->setText(dataArray[page]);
    qDebug() << page;

}
void isaac::changeDisplay(QString p)
{
    QPixmap mypix(p);
    ui->lb_background->setPixmap(mypix);
}
void isaac::checkDisplay(int index)
{
    if((page > 0) && (page < 8))
    {
        wgroup(true);
    }else {
        wgroup(false);
    }
    if(page ==8){
        ui->lb_old->setText(dataArray[1]);
        ui->lb_child->setText(dataArray[2]);
        ui->lb_man->setText(dataArray[3]);
        ui->lb_women->setText(dataArray[4]);
        ui->lb_bag->setText(dataArray[5]);
        ui->lb_trans->setText(dataArray[6]);
        ui->lb_emer->setText(dataArray[7]);

        ui->lb_old->setVisible(true);
        ui->lb_child->setVisible(true);
        ui->lb_man->setVisible(true);
        ui->lb_women->setVisible(true);
        ui->lb_bag->setVisible(true);
        ui->lb_trans->setVisible(true);
        ui->lb_emer->setVisible(true);

    }else{
        ui->lb_bag->setVisible(false);
        ui->lb_child->setVisible(false);
        ui->lb_emer->setVisible(false);
        ui->lb_man->setVisible(false);
        ui->lb_old->setVisible(false);
        ui->lb_trans->setVisible(false);
        ui->lb_women->setVisible(false);

    }
    if(page ==9)
    {
        //Progress bar
        ui->pb_transmit->setValue(30);
        ui->pb_transmit->setVisible(true);
    }else {
        ui->pb_transmit->setVisible(false);
    }
    switch (index) {
        case 0 : {
        changeDisplay(p1);
    }break;
    case 1 : {
           changeDisplay(p2);
    }break;
    case 2 : {
            changeDisplay(p3);
    }break;
    case 3 : {
            changeDisplay(p4);
    }break;
    case 4 : {
            changeDisplay(p5);
    }break;
    case 5 : {
            changeDisplay(p6);
    }break;
    case 6 : {
            changeDisplay(p7);
    }break;
    case 7 : {
            changeDisplay(p8);
    }break;
    case 8 : {
            changeDisplay(p9);
    }break;
    case 9 : {
            changeDisplay(p10);
    }break;
    case 10 : {
            changeDisplay(p11);
    }break;

    }
}

void isaac::on_bt_plus_clicked()
{
    int temp =ui->lb_value->text().toInt();
    temp++;
    ui->lb_value->setText(QString::number(temp));
}

void isaac::on_bt_neg_clicked()
{
    int temp =ui->lb_value->text().toInt();
    temp--;
    if(temp<0)
        temp=0;
    ui->lb_value->setText(QString::number(temp));
}
void isaac::wgroup(bool en)
{
    if(!en){
    ui->bt_neg->setVisible(false);
    ui->bt_plus->setVisible(false);
    ui->lb_value->setVisible(false);
    }else {
        ui->bt_neg->setVisible(true);
        ui->bt_plus->setVisible(true);
        ui->lb_value->setVisible(true);
    }
}
void isaac::keylog(int key)
{
    qDebug() << key;
}
/*
void isaac::on_pushButton_3_clicked()
{

    qDebug() << "Back press = " << digitalRead(bt_back_pin);
    qDebug() << "Next press = " << digitalRead(bt_add_pin);
    qDebug() << "Minus press = " << digitalRead(bt_minus_pin);
    qDebug() << "Add press = " << digitalRead(bt_add_pin);
}
*/
