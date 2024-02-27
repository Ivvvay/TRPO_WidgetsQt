#ifndef FIGURA_H
#define FIGURA_H

#include <QPainter>

class Figura                                                // Абстрактный класс, используется как родитель для создания конкретных фигур
{
protected:
    int x,y,halfLength,dx,dy;                               // Координаты расположения центра фигуры, Половина от длины фигуры и Координаты вектора, указывающего наклон фигуры

    virtual void draw(QPainter *Painter)=0;                 // Виртуальная функция для отрисовки фигуры
public:
    Figura(int X,int Y,int Halflen)
        : x(X),y(Y),halfLength(Halflen) {}                  // Конструктор(определяет положение фигуры(x, y)

    void move(float Alpha,QPainter *Painter);               // Функция движения фигуры
};

class MyLine : public Figura                                  // Класс линии
{
protected:
    void draw(QPainter *Painter);
public:
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){}
};


class MyRect : public Figura                                  //Класс прямоугольника
{
protected:
    void draw(QPainter *Painter);
public:
    MyRect(int x,int y,int halflen):Figura(x,y,halflen){}
};

#endif // FIGURA_H
