#include "area.h"

Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300,200));                   // Установка зафиксированного размера виджета
    myline=new MyLine(80, 100, 50);                 // Создание фигур
    myrect=new MyRect(220, 100, 50);
    alpha=0;                                        // Инициаллизация начального угла поворота фигур
}

void Area::showEvent(QShowEvent *)                  // Обработчик события появления виджета
{
    myTimer=startTimer(50);                         // Создать таймер
}

void Area::paintEvent(QPaintEvent *)                // Обработчик события отрисовки виджета
{
    QPainter painter(this);                         // Создание объекта рисования
    painter.setPen(Qt::red);                        // Назначение ему красного цвета
    myline->move(alpha,&painter);                   // Движение линии
    myrect->move(alpha*(-0.5),&painter);            // Движение прямоугольника
}

void Area::timerEvent(QTimerEvent *event)           // Обработчик таймера
{
    if (event->timerId() == myTimer) {              // Если наш таймер
        alpha += 0.2;                               // Изменение угла
        update();                                   // Обновить внешний вид
    } else
        QWidget::timerEvent(event);                 // Иначе передать для стандартной обработки
}

void Area::hideEvent(QHideEvent *)                  // Обработчик события когда виджет скрыли
{
    killTimer(myTimer);                             // Уничножить таймер
}

Area::~Area()                                       // Деструктор виджета
{
    delete myline;                                  // Удаление линии
    delete myrect;                                  // Удаление прямоуг
}
