#include "somedaytaskareawidget.h"
#include "ui_todoareawidget.h"

SomeDayTaskAreaWidget::SomeDayTaskAreaWidget()
{
        filePath = "someDayTask.bin";
}

void SomeDayTaskAreaWidget::on_addToDoButton_clicked()
{
    if(ui->addToDoLineEdit->text() != "")
    {
         SomeDayTaskWidget * someTask = new SomeDayTaskWidget(priorityWidget->getImportance());
         someTask->setText(ui->addToDoLineEdit->text());
         QObject::connect(someTask, SIGNAL(deleteToDo(ToDoWidget*)),this, SLOT(on_deleteToDo_clicked(ToDoWidget*)));

         toDoList.push_back(someTask);
         ui->ScrollAreaLayout->addWidget(someTask);

         ui->addToDoFrame->hide();
         ui->addToDoLineEdit->clear();
    }
}

void SomeDayTaskAreaWidget::readToDoFromfile()
{
    QFile fileIn(filePath);
    if(fileIn.open(QIODevice::ReadOnly))
    {
        QDataStream stream(&fileIn);
        stream.setVersion(QDataStream::Qt_4_5);

        while (!fileIn.atEnd())
        {
            SomeDayTaskWidget * tempTask = new SomeDayTaskWidget;
            stream >> *tempTask;

            if( QDate::currentDate().daysTo(tempTask->getComplitionDate()) > 1)
            {
                QObject::connect(tempTask, SIGNAL(deleteToDo(ToDoWidget*)),this, SLOT(on_deleteToDo_clicked(ToDoWidget*)));
                toDoList.push_back(tempTask);
                ui->ScrollAreaLayout->addWidget(tempTask);
            }
            else
            {
                if(QDate::currentDate().daysTo(tempTask->getComplitionDate()) == 1)
                {
                    emit moveTaskToTommorow(*tempTask);
                    qDebug() << "send to tommorow";
                }
                else
                {
                    emit moveTaskToToday(*tempTask);
                }

                delete tempTask;
            }
        }
    } else     qDebug() << "error open file int taskArea";                                                                                                      //else throw

    fileIn.close();
}
