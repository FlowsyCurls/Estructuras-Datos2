#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Client");
    ui->tableWidget->setStyleSheet("QTableView {selection-background-color: red;}");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_connect_clicked()
{
    util.runClient(); //client start.
}

void Widget::on_start_clicked()
{
    //client ask server for data.
    util.start(this->ui->tableWidget);
}

void Widget::on_quit_clicked()
{
    close();
}
