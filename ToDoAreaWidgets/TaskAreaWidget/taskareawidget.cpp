#include "taskareawidget.h"
#include "ui_todoareawidget.h"

TaskAreaWidget::TaskAreaWidget()
{
    priorityWidget = new PriorityWidget;
    ui->addToDoLayout->addWidget(priorityWidget);

    filePath = "task.bin";
}

TaskAreaWidget::~TaskAreaWidget(){
    delete priorityWidget;
}

void TaskAreaWidget::readToDoFromfile()
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
            QObject::connect(tempTask, SIGNAL(deleteToDo(ToDoWidget*)),this, SLOT(on_deleteToDo_clicked(ToDoWidget*)));

            toDoList.push_back(tempTask);
            ui->ScrollAreaLayout->addWidget(tempTask);
        }
    } else     qDebug() << "error open file int taskArea";                                                                                                      //else throw

    fileIn.close();
}

void TaskAreaWidget::on_addToDoButton_clicked()
{
    if(ui->addToDoLineEdit->text() != "")
    {
         TaskWidget * someTask = new TaskWidget(priorityWidget->getImportance());
         someTask->setText(ui->addToDoLineEdit->text());
         QObject::connect(someTask, SIGNAL(deleteToDo(ToDoWidget*)),this, SLOT(on_deleteToDo_clicked(ToDoWidget*)));

         toDoList.push_back(someTask);
         ui->ScrollAreaLayout->addWidget(someTask);

         ui->addToDoFrame->hide();
         ui->addToDoLineEdit->clear();
    }
}

void TaskAreaWidget::addTaskFromOtherArea(TaskWidget movedTask)
{
    TaskWidget * tempTask = new TaskWidget(movedTask);
    QObject::connect(tempTask, SIGNAL(deleteToDo(ToDoWidget*)),this, SLOT(on_deleteToDo_clicked(ToDoWidget*)));

    toDoList.push_back(tempTask);
    ui->ScrollAreaLayout->addWidget(tempTask);
}



