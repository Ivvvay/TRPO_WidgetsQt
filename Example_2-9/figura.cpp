#include "figura.h"

#include <math.h>

void Figura::move(float Alpha,QPainter *Painter)            // Функция движения фугуры
{
    dx=halfLength*cos(Alpha);                               // Расчет вектора (dx, dy), задающего угол наклона
    dy=halfLength*sin(Alpha);
    draw(Painter);
}

void MyLine::draw(QPainter *Painter)
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);                 // Отрисовывает в нем линию с центром в (x, y), параллельную вектору (dx, dy)
}

void MyRect::draw(QPainter *Painter)
{
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);                 // Отрисовка граней прямоугольника с центром в (x, y)
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);                 // и диагональю, параллельной вектору (dx, dy) (другая диагональ перепендикулярна этому вектору)
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
