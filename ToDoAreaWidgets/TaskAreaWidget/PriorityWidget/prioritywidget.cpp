#include "prioritywidget.h"
#include "ui_prioritywidget.h"

PriorityWidget::PriorityWidget() : ui(new Ui::PriorityWidget)
{
    ui->setupUi(this);
}

PriorityWidget::~PriorityWidget()
{
    delete ui;
}

importanceDegree PriorityWidget::getImportance(){
    if(ui->lightlyButton->isChecked()){
        return lightly;
    }
    if(ui->importantButton->isChecked()){
        return important;
    }
    if(ui->veryImportantButton->isChecked()){
        return veryImportant;
    }

    //throw
}
