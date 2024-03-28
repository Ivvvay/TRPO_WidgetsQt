#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class Counter : public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString &contents, QWidget *parent = nullptr)
        : QLineEdit(contents, parent) {}

signals:
    void tick_signal();

public slots:
    void add_one();

};

class Widget : public QWidget
{
    Q_OBJECT
protected:
    QLabel *label1, *label2;
    Counter *edit1, *edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
