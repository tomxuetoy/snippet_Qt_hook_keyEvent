#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <qevent.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
    ui->textEdit->installEventFilter(this); //to install the customized eventFilter(hook function)
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)   //hook function, by Tom
{
    if (obj == ui->textEdit)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            qDebug() << "Ate key press" << keyEvent->key();
            //eventFilter函数返回true时表示该事件处理完毕， 不再继续传递；返回false表示该事件仍然传递
            return false;
        }
        else
        {
            return false;
        }
    }

    else
    {
        // pass the event on to the parent class
        return QMainWindow::eventFilter(obj, event);
    }
}
