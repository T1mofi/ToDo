#pragma once

#include "ToDoAreaWidgets/TaskAreaWidget/taskareawidget.h"

class TomorrowTaskAreaWidget : public TaskAreaWidget
{
    Q_OBJECT
public:
    TomorrowTaskAreaWidget();

    void readToDoFromfile() override;

signals:
    void moveTask(TaskWidget moveTask);
};

