#pragma once

#include "ToDoAreaWidgets/TaskAreaWidget/taskareawidget.h"
#include "DateWidget/datewidget.h"

class SomeDayTaskAreaWidget : public TaskAreaWidget
{
    Q_OBJECT
public:
    SomeDayTaskAreaWidget();

    void readToDoFromfile() override;

signals:
    void moveTaskToTommorow(TaskWidget moveTask);
    void moveTaskToToday(TaskWidget moveTask);

private slots:
    void on_addToDoButton_clicked() override;
private:
    DateWidget * dateWidget;
};

