#pragma once
#include <QDate>
#include "ToDoWidgets/TaskWidget/taskwidget.h"

class SomeDayTaskWidget : public TaskWidget
{
public:
    SomeDayTaskWidget(const QDate& newComplitionDate = QDate::currentDate().addDays(2));

    friend inline QDataStream& operator<<(QDataStream &out, const SomeDayTaskWidget& task);
    friend inline QDataStream& operator>>(QDataStream &in, SomeDayTaskWidget& task);

private:
    QDate complitionDate;
    QLabel * dateLabel;
};

inline QDataStream& operator<<(QDataStream &out, const SomeDayTaskWidget& task){

    out << task.getText();
    out << task.creationDate;
    out << static_cast<int>(task.taskPriority.getImportanceDegree());
    out << task.complitionDate;

    return  out;
}

inline QDataStream& operator>>(QDataStream &in, SomeDayTaskWidget& task){
    QString tempNote;
    in >> tempNote;
    task.setText(tempNote);

    in >> task.creationDate;

    int tempImportance;
    in >> tempImportance;
    task.setPriority(static_cast<importanceDegree>(tempImportance));

    in >> task.complitionDate;

    return  in;
}


