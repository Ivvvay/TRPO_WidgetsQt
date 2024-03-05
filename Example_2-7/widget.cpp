#include "widget.h"

#include <QBoxLayout>
#include <QMessageBox>
#include <QTextCodec>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    setWindowTitle("Возведение в квадрат");

    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);
    inputTitle = new QLabel("Введите число:", this);
    inputEdit = new QLineEdit("",this);

    StrValidator *v = new StrValidator(inputEdit);
    inputEdit->setValidator(v);

    outputTitle = new QLabel("Результат:", this);
    outputEdit = new QLineEdit("",this);

    nextButton = new QPushButton("Следующее", this);
    exitButton = new QPushButton("Выход", this);

    QVBoxLayout *vLayoutForNumbers = new QVBoxLayout(frame);
    vLayoutForNumbers->addWidget(inputTitle);
    vLayoutForNumbers->addWidget(inputEdit);
    vLayoutForNumbers->addWidget(outputTitle);
    vLayoutForNumbers->addWidget(outputEdit);
    vLayoutForNumbers->addStretch();

    QVBoxLayout *vLayoutForButtons = new QVBoxLayout();
    vLayoutForButtons->addWidget(nextButton);
    vLayoutForButtons->addWidget(exitButton);
    vLayoutForButtons->addStretch();

    QHBoxLayout *hLayoutGeneral = new QHBoxLayout(this);
    hLayoutGeneral->addWidget(frame);
    hLayoutGeneral->addLayout(vLayoutForButtons);

    begin();

    connect(exitButton,SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(nextButton,SIGNAL(clicked(bool)), this, SLOT(begin()));
    connect(inputEdit,SIGNAL(returnPressed()), this, SLOT(calc()));
}

Widget::~Widget()
{
}

void Widget::begin()
{
    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    inputEdit->clear();
    inputEdit->setEnabled(true);
    outputTitle->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();
}

void Widget::calc()
{
    bool Ok = true;
    float r,a;
    QString str=inputEdit->text();

    try {
        a = str.toDouble(&Ok);

        if(!qIsFinite(a)) {
            throw std::overflow_error("Переполнение");
        }

        if (Ok) {
            r = a*a;

            if(!qIsFinite(r)) {
                throw std::overflow_error("Переполнение");
            }

            str.setNum(r);
            outputEdit->setText(str);
            inputEdit->setEnabled(false);
            outputTitle->setVisible(true);
            outputEdit->setVisible(true);
            nextButton->setDefault(true);
            nextButton->setEnabled(true);
            nextButton->setFocus();
        } else
            if (!str.isEmpty()) {
                throw std::invalid_argument("Введено неверное значение.");
            }
    } catch (std::exception &e) {
        QMessageBox msgBox(QMessageBox::Information, "Возведение в квадрат.",
                           e.what(), QMessageBox::Ok);
        msgBox.exec();
        inputEdit->clear();
    }

}
