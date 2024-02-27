#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class Counter : public QLineEdit                                    // Класс виджета строки счетчика
{
    Q_OBJECT                                                        // Макрос подключения слотов и сигналов к классу
public:
    Counter(const QString &contents, QWidget *parent=0)            // Конструктор
        : QLineEdit(contents,parent) {}

signals:
    void tick_signal();                                             // Сигнал, срабатывает когда счетчик кратен 5

public slots:
    void add_one();                                                 // Слот, добавляющий 1 к счетчику

};

class Widget : public QWidget
{
    Q_OBJECT
protected:
    QLabel *label1,*label2;                                         // Заголовки над счетчиками
    Counter *edit1,*edit2;                                          // Счетчики
    QPushButton *calcbutton;                                        // Кнопка добавления 1 к счетчику
    QPushButton *exitbutton;                                        // Кнопка Выход

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
