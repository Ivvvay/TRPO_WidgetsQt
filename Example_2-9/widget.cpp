#include "widget.h"
#include <QTextCodec>
#include <QBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    this->setWindowTitle("Обработка событий");

    area = new Area(this);
    btn = new QPushButton("Завершить",this );

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btn);

    connect(btn, &QPushButton::clicked, this, &Widget::close);
}

Widget::~Widget()
{
}

