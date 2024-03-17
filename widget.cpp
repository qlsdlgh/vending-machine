#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

int money{0};

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeEnable();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money+=diff;
    ui->lcdNumber->display(money);

    changeEnable();
}

void Widget::changeEnable(){
    ui->pushButton_5->setEnabled(money>=100);
    ui->pushButton_6->setEnabled(money>=150);
    ui->pushButton_7->setEnabled(money>=200);
}

void Widget::on_pushButton_clicked()
{
    changeMoney(10);
}

void Widget::on_pushButton_2_clicked()
{
    changeMoney(50);
}


void Widget::on_pushButton_3_clicked()
{
    changeMoney(100);
}


void Widget::on_pushButton_4_clicked()
{
    changeMoney(500);
}


void Widget::on_pushButton_5_clicked()
{
    changeMoney(-100);
}


void Widget::on_pushButton_6_clicked()
{
    changeMoney(-150);
}


void Widget::on_pushButton_7_clicked()
{
    changeMoney(-200);
}


void Widget::on_pushButton_8_clicked()
{
    int coin500 = money / 500;
    money %= 500;
    QString str_coin500 = QString::number(coin500);
    int coin100 = money / 100;
    money %= 100;
    QString str_coin100 = QString::number(coin100);
    int coin50 = money / 50;
    money %= 50;
    QString str_coin50 = QString::number(coin50);
    int coin10 = money / 10;
    money %= 10;
    QString str_coin10 = QString::number(coin10);

    QMessageBox mb;
    mb.information(nullptr,"return", "500: " + str_coin500 + "\n100: " + str_coin100 + "\n 50:" + str_coin50 + "\n 10:" + str_coin10);
    money = 0;
    ui->lcdNumber->display(money);
    changeEnable();
}
