#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

//int money = 0;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n)
{
    money+=n;
    ui->lcdNumber->display(money);
}

void Widget::checkMoney()
{

    if(money < 100)
        ui->pbCoffee->setEnabled(false);
     else if(money >= 100)
        ui->pbCoffee->setEnabled(true);

    if(money < 150)
        ui->pbTea->setEnabled(false);
    else if(money >= 150)
        ui->pbTea->setEnabled(true);

    if(money < 200)
        ui->pbCoke->setEnabled(false);
    else if(money >= 200)
        ui->pbCoke->setEnabled(true);



}

void Widget::returnCoin(int n)
{

    fivehundredcoin = n / 500;
    onehundredcoin = (n % 500) / 100;
    fiftycoin = ((n % 500) % 100) / 50;
    tencoin = (((n % 500) % 100) %50) /10;

    money -= money;
    ui->lcdNumber->display(money);
    checkMoney();
}

void Widget::on_PB_10_clicked()
{

    changeMoney(10);
    checkMoney();

}

void Widget::on_PB_50_clicked()
{
    changeMoney(50);
   checkMoney();

}

void Widget::on_PB_100_clicked()
{
    changeMoney(100);
    checkMoney();

}

void Widget::on_PB_500_clicked()
{
    changeMoney(500);
    checkMoney();

}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    checkMoney();

}

void Widget::on_pbTea_clicked()
{

    changeMoney(-150);
    checkMoney();


}

void Widget::on_pbCoke_clicked()
{


    changeMoney(-200);
    checkMoney();


}

void Widget::on_pbreturnCoin_clicked()
{
    returnCoin(money);

    QString status = QString("500Coin : %1 \n 100Coin : %2 \n 50coin : %3 \n 10Coin : %4")
            .arg(fivehundredcoin)
            .arg(onehundredcoin)
            .arg(fiftycoin)
            .arg(tencoin);

    QMessageBox msg;
    msg.information(nullptr, "Return", status);
}
