#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "util.h"

namespace Ui {
class Widget;
}

//class included
class Util;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_connect_clicked();

    void on_start_clicked();

    void on_quit_clicked();

private:
    Ui::Widget *ui;
    Util util;
    Client *client;

};

#endif // WIDGET_H
