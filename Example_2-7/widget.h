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
    Widget(QWidget *parent = nullptr);              // Конструктор
    ~Widget();                                      // Деструктор

protected:
    QFrame *frame;                                  // Рамка
    QLabel *inputTitle;                             // Метка ввода
    QLineEdit *inputEdit;                           // Строчный редактор ввода
    QLabel *outputTitle;                            // Метка вывода
    QLineEdit *outputEdit;                          // Строчный редактор вывода
    QPushButton *nextButton;                        // Кнопка Следующее
    QPushButton *exitButton;                        // Кнопка Выход

public slots:
    void begin();                                   // Слот для очитки виджета и подготовки его к новому вычислению
    void calc();                                    // Слот для вычисления
};

class StrValidator : public QValidator              // класс компонента проверки ввода
{
public:
    StrValidator(QObject *parent):QValidator(parent){}

    virtual State validate(QString &str, int &pos) const
    {
        return Acceptable;                          // метод всегда принимает вводимую строку
    }
};

#endif // WIDGET_H
