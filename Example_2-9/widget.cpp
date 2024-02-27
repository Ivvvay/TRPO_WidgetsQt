#include "widget.h"
#include <QTextCodec>
#include <QBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));    // Кодек для локализации на русском
    this->setWindowTitle("Обработка событий");                                  // Заголовок окна
    area = new Area(this);                                                      // Создание Area
    btn = new QPushButton("Завершить",this );                                   // Создание Кнопки
    QVBoxLayout *layout = new QVBoxLayout(this);                                // Вертикальная разметка

    layout->addWidget(area);                                                    // Помещение на вертикальную разметку зону с фигурами и кнопку
    layout->addWidget(btn);

    connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));                     // Подключение сигнала нажатия кнопки к слоту закрытия окна
}

Widget::~Widget()
{
}

