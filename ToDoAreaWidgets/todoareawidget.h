#pragma once

#include <QFile>
#include <QDataStream>

#include <QWidget>
#include <QList>
#include <QDebug>

#include "ToDoWidgets/TaskWidget/SomeDayTaskWidget/somedaytaskwidget.h"

namespace Ui {
class ToDoAreaWidget;
}

class ToDoAreaWidget : public QWidget
{
    Q_OBJECT

public:
    ToDoAreaWidget();
    virtual ~ToDoAreaWidget();

    virtual void readToDoFromfile() = 0;
    void writeToDoInfile();

private slots:
    void on_backButton_clicked();
    void on_newToDoButton_clicked();

    virtual void on_addToDoButton_clicked() = 0;
    void on_addToDoLineEdit_returnPressed();
    void on_deleteToDo_clicked(ToDoWidget* deletedToDo);



protected:
    Ui::ToDoAreaWidget *ui;
    QString filePath;
    QList<ToDoWidget*> toDoList;
};
