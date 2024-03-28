#ifndef FIGURA_H
#define FIGURA_H

#include <QPainter>

class Figura
{
protected:
    int x, y, halfLength, dx, dy;

    virtual void draw(QPainter *Painter) = 0;

public:
    Figura(int X,int Y,int Halflen)
        : x(X),y(Y),halfLength(Halflen) {}

    void move(float Alpha,QPainter *Painter);
};

class MyLine : public Figura
{
protected:
    void draw(QPainter *Painter);

public:
    MyLine(int x,int y,int halflen)
        : Figura(x,y,halflen){}
};


class MyRect : public Figura
{
protected:
    void draw(QPainter *Painter);

public:
    MyRect(int x,int y,int halflen)
        : Figura(x,y,halflen){}
};

#endif // FIGURA_H
