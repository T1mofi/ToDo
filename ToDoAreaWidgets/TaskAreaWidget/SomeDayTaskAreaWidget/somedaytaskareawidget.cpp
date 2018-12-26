#include "somedaytaskareawidget.h"
#include "ui_todoareawidget.h"

SomeDayTaskAreaWidget::SomeDayTaskAreaWidget()
{

}

void SomeDayTaskAreaWidget::on_addToDoButton_clicked()
{
    if(ui->addToDoLineEdit->text() != "")
    {
         SomeDayTaskWidget * someTask = new SomeDayTaskWidget;
         someTask->setText(ui->addToDoLineEdit->text());
         QObject::connect(someTask, SIGNAL(deleteToDo(ToDoWidget*)),this, SLOT(on_deleteToDo_clicked(ToDoWidget*)));

         toDoList.push_back(someTask);
         ui->ScrollAreaLayout->addWidget(someTask);

         ui->addToDoFrame->hide();
         ui->addToDoLineEdit->clear();
    }
}
