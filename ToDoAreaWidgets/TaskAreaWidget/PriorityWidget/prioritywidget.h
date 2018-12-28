#pragma once

#include <QWidget>
#include "ToDoWidgets/TaskWidget/Priority/specialtypes.h"

namespace Ui {
class PriorityWidget;
}

class PriorityWidget : public QWidget
{
    Q_OBJECT

public:
    PriorityWidget();
    ~PriorityWidget();

    importanceDegree getImportance();

private:
    Ui::PriorityWidget *ui;
};
