#include "tomorrowtaskareawidget.h"
#include "ui_todoareawidget.h"

TomorrowTaskAreaWidget::TomorrowTaskAreaWidget()
{
    filePath = "tomorrowTask.bin";
}

void TomorrowTaskAreaWidget::readToDoFromfile()
{
    QFile fileIn(filePath);
    if(fileIn.open(QIODevice::ReadOnly))
    {
        QDataStream stream(&fileIn);
        stream.setVersion(QDataStream::Qt_4_5);

        while (!fileIn.atEnd())
        {
            TaskWidget * tempTask = new TaskWidget;
            stream >> *tempTask;

            if( tempTask->getCreationDate().daysTo(QDate::currentDate()) == 0){
                QObject::connect(tempTask, SIGNAL(deleteToDo(ToDoWidget*)),this, SLOT(on_deleteToDo_clicked(ToDoWidget*)));

                toDoList.push_back(tempTask);
                ui->ScrollAreaLayout->addWidget(tempTask);
            }
            else
            {
                emit moveTask(*tempTask);
                delete tempTask;
            }
        }
    } else     qDebug() << "error open file int taskArea";                                                                                                      //else throw

    fileIn.close();
}
