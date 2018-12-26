#pragma once

#include <QFile>
#include <QDataStream>

#include "ToDoAreaWidgets/todoareawidget.h"
#include "ToDoWidgets/todowidget.h"

class IdeaAreaWidget : public ToDoAreaWidget
{
    Q_OBJECT
public:
    IdeaAreaWidget();

    void readToDoFromfile() override;

private slots:
    void on_addToDoButton_clicked() override;
};
