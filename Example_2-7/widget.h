#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QValidator>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    QFrame *frame;
    QLabel *inputTitle;
    QLineEdit *inputEdit;
    QLabel *outputTitle;
    QLineEdit *outputEdit;
    QPushButton *nextButton;
    QPushButton *exitButton;

public slots:
    void begin();
    void calc();
};

class StrValidator : public QValidator
{
public:
    StrValidator(QObject *parent):QValidator(parent) {}

    virtual State validate(QString &str, int &pos) const
    {
        return Acceptable;
    }
};

#endif // WIDGET_H
