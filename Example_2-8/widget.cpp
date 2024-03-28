#include "widget.h"
#include <QTextCodec>
#include <QBoxLayout>
#include <QMessageBox>

void Counter::add_one()
{
    QString str = text();
    int r = str.toInt();

    r++;

    if (r != 0 && r % 5 == 0) {
        emit tick_signal();
    }

    str.setNum(r);
    setText(str);
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));

    this->setWindowTitle("Счетчик");

    try {
        label1 = new QLabel("Cчет по 1",this);
        label2 = new QLabel("Cчет по 5",this);
        edit1 = new Counter("0",this);
        edit2 = new Counter("0",this);

        calcbutton = new QPushButton("+1",this);
        exitbutton = new QPushButton("Выход",this);

        QHBoxLayout *layout1 = new QHBoxLayout();
        layout1->addWidget(label1);
        layout1->addWidget(label2);

        QHBoxLayout *layout2 = new QHBoxLayout();
        layout2->addWidget(edit1);
        layout2->addWidget(edit2);

        QHBoxLayout *layout3 = new QHBoxLayout();
        layout3->addWidget(calcbutton);
        layout3->addWidget(exitbutton);

        QVBoxLayout *layout4 = new QVBoxLayout(this);
        layout4->addLayout(layout1);
        layout4->addLayout(layout2);
        layout4->addLayout(layout3);
        layout4->addStretch();

    } catch (std::bad_alloc&) {
        QMessageBox::critical(this, "Ошибка", "Не удалось выделить память для одного из объектов");
        exit(1);
    }

    edit1->setEnabled(false);
    edit2->setEnabled(false);

    connect(calcbutton,&QPushButton::clicked, edit1, &Counter::add_one);
    connect(edit1, &Counter::tick_signal, edit2, &Counter::add_one);
    connect(exitbutton, &QPushButton::clicked, this, &Widget::close);
}

Widget::~Widget()
{
}
