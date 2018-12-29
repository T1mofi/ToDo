#include "todowidget.h"
#include "ui_todowidget.h"

ToDoWidget::ToDoWidget() : ui(new Ui::ToDoWidget)
{
    ui->setupUi(this);
    ui->deleteToDoButton->hide();
}

ToDoWidget::ToDoWidget(const ToDoWidget& other)
{
    ui = new Ui::ToDoWidget;
    ui->setupUi(this);
    ui->deleteToDoButton->hide();
    ui->toDoNoteLabel->setText(other.getText());
}

ToDoWidget& ToDoWidget::operator=(const ToDoWidget& other)
{
    ui->deleteToDoButton->hide();
    ui->toDoNoteLabel->setText(other.getText());

    return *this;
}

ToDoWidget::~ToDoWidget()
{
    delete ui;
}

void ToDoWidget::setText(QString note)
{
    ui->toDoNoteLabel->setText(note);
}

QString ToDoWidget::getText() const
{
    return ui->toDoNoteLabel->text();
}

void ToDoWidget::on_compliteToDoCheckBox_clicked(bool checked)
{
    if(checked == true)
    {
        ui->deleteToDoButton->show();
    }else
    {
        ui->deleteToDoButton->hide();
    }
}

void ToDoWidget::on_deleteToDoButton_clicked()
{
    emit deleteToDo(this);
}
