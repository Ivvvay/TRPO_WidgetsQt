#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "area.h"
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

protected:
    Area * area;
    QPushButton * btn;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
