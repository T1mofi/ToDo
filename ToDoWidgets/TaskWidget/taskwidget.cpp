#include "taskwidget.h"
#include "ui_todowidget.h"

TaskWidget::TaskWidget(importanceDegree taskImportance) : taskPriority(taskImportance)
{
   creationDate = QDate::currentDate();

   ui->ToDoWidgetFrame->setStyleSheet(taskPriority.getImportanceStyle());
}

TaskWidget::TaskWidget(const TaskWidget& other) : ToDoWidget (other)
{
    creationDate = other.creationDate;
    taskPriority = other.taskPriority;
    ui->ToDoWidgetFrame->setStyleSheet(other.taskPriority.getImportanceStyle());
}

TaskWidget& TaskWidget::operator=(const TaskWidget& other)
{
    this->ToDoWidget::operator=(other);
    creationDate = other.creationDate;
    taskPriority = other.taskPriority;
    ui->ToDoWidgetFrame->setStyleSheet(other.taskPriority.getImportanceStyle());

    return *this;
}

TaskWidget::~TaskWidget()
{

}

void TaskWidget::setPriority(importanceDegree taskImportance){
    taskPriority.setImportance(taskImportance);
    ui->ToDoWidgetFrame->setStyleSheet(taskPriority.getImportanceStyle());
}

QDate TaskWidget::getCreationDate()
{
    return creationDate;
}
