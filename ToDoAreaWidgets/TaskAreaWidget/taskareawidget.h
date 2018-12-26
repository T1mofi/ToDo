#pragma once

#include <QFile>
#include <QDataStream>

#include "ToDoAreaWidgets/todoareawidget.h"
#include "PriorityWidget/prioritywidget.h"
#include "ToDoWidgets/TaskWidget/taskwidget.h"

class TaskAreaWidget : public ToDoAreaWidget
{
    Q_OBJECT
public:
    TaskAreaWidget();
    ~TaskAreaWidget() override;

    void readToDoFromfile() override;

private slots:
    void on_addToDoButton_clicked() override;
    void addTaskFromOtherArea(TaskWidget movedTask);

private:
    PriorityWidget * priorityWidget;
};

