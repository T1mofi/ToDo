#include "ideaareawidget.h"
#include "ui_todoareawidget.h"

IdeaAreaWidget::IdeaAreaWidget()
{
    filePath = "idea.bin";
}

void IdeaAreaWidget::readToDoFromfile()
{
    QFile fileIn(filePath);
    if(fileIn.open(QIODevice::ReadOnly))
    {
        QDataStream stream(&fileIn);
        stream.setVersion(QDataStream::Qt_4_5);

        while (!fileIn.atEnd())
        {
            ToDoWidget * tempTask = new ToDoWidget;
            stream >> *tempTask;
            QObject::connect(tempTask, SIGNAL(deleteToDo(ToDoWidget*)),this, SLOT(on_deleteToDo_clicked(ToDoWidget*)));

            toDoList.push_back(tempTask);
            ui->ScrollAreaLayout->addWidget(tempTask);
        }
    } else     qDebug() << "error open file int taskArea";                                                                                                      //else throw

    fileIn.close();
}

void IdeaAreaWidget::on_addToDoButton_clicked()
{
    if(ui->addToDoLineEdit->text() != "")
    {
         ToDoWidget * someTask = new ToDoWidget;
         someTask->setText(ui->addToDoLineEdit->text());
         QObject::connect(someTask, SIGNAL(deleteToDo(ToDoWidget*)),this, SLOT(on_deleteToDo_clicked(ToDoWidget*)));

         toDoList.push_back(someTask);
         ui->ScrollAreaLayout->addWidget(someTask);

         ui->addToDoFrame->hide();
         ui->addToDoLineEdit->clear();
    }
}
