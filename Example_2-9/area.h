#ifndef AREA_H
#define AREA_H

#include "figura.h"
#include <QWidget>
#include <QTimerEvent>

class Area : public QWidget         // Виджет с крутящимися линией и прямоугольником
{
private:
    int myTimer;                    // Таймер
    float alpha;                    // Угол поворота
public:
    Area(QWidget *parent = 0);
    ~Area();
    MyLine *myline;                 // Линия
    MyRect *myrect;                 // Прямоугольник

protected:
    // Обработчики событий
    void paintEvent(QPaintEvent *event);        // Обработчик события отрисовки виджета
    void timerEvent(QTimerEvent *event);        // Обработчик события таймера
    void showEvent(QShowEvent *event);          // Обработчик события появления виджета
    void hideEvent(QHideEvent *event);          // Обработчик события когда виджет скрыли
};

#endif // AREA_H
