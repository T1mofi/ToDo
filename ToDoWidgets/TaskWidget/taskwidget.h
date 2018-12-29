#pragma once

#include <QLabel>
#include <QDate>

#include "ToDoWidgets/todowidget.h"
#include "Priority/priority.h"

#include <QDebug>


class TaskWidget : public ToDoWidget
{
public:
    explicit TaskWidget(importanceDegree taskImportance = lightly);
    TaskWidget(const TaskWidget& other);
    TaskWidget& operator=(const TaskWidget& other);
    ~TaskWidget();

    friend inline QDataStream& operator<<(QDataStream &out, const TaskWidget& task);
    friend inline QDataStream& operator>>(QDataStream &in, TaskWidget& task);

    void setPriority(importanceDegree taskImportance);
    void setCreationDate(QDate newCreationDate);
    QDate getCreationDate();
protected:
    QDate creationDate;
    Priority taskPriority;
};

inline QDataStream& operator<<(QDataStream &out, const TaskWidget& task){

    out << task.getText();
    out << task.creationDate;
    out << static_cast<int>(task.taskPriority.getImportanceDegree());

    return  out;
}

inline QDataStream& operator>>(QDataStream &in, TaskWidget& task){
    QString tempNote;
    in >> tempNote;
    task.setText(tempNote);

    in >> task.creationDate;

    int tempImportance;
    in >> tempImportance;
    task.setPriority(static_cast<importanceDegree>(tempImportance));

    return  in;
}
