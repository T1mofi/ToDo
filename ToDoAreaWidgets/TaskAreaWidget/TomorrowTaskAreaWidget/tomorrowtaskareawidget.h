#pragma once

#include "ToDoAreaWidgets/TaskAreaWidget/taskareawidget.h"

class TomorrowTaskAreaWidget : public TaskAreaWidget
{
    Q_OBJECT
public:
    TomorrowTaskAreaWidget(QString newFilePath);

    void readToDoFromfile(QString filePath) override;

signals:
    void moveTask(TaskWidget moveTask);
};

