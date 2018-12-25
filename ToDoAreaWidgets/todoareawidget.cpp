#include "todoareawidget.h"
#include "ui_todoareawidget.h"

ToDoAreaWidget::ToDoAreaWidget() : ui(new Ui::ToDoAreaWidget)
{
    ui->setupUi(this);

    ui->addToDoFrame->hide();
    ui->ScrollAreaLayout->setAlignment(Qt::AlignTop);       //new ToDo to the top

    filePath = "reserveToDo.bin";
}

ToDoAreaWidget::~ToDoAreaWidget()
{
    writeToDoInfile();

    for(QList<ToDoWidget*>::iterator it = toDoList.begin();it != toDoList.end(); ++it)
    {
            delete *it;
    }

    delete ui;
}

void ToDoAreaWidget::writeToDoInfile()
{
    QFile file(filePath);
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream stream(&file);
        stream.setVersion(QDataStream::Qt_4_5);

        for(QList<ToDoWidget*>::iterator it = toDoList.begin(); it != toDoList.end(); it++){
            if(filePath == "task.bin" || filePath == "tomorrowTask.bin")
                stream << *(dynamic_cast<TaskWidget*>(*it));                                                  //add try cath
            if(filePath == "reserveToDo.bin")
                stream << **it;
        }

        if (stream.status() != QDataStream::Ok) {
            qDebug() << "Ошибка записи";
        }
    }else qDebug() << "error with file opening in ToDoAreaWidget";              //add try catch
    file.close();
}

void ToDoAreaWidget::on_backButton_clicked()
{
    this->hide();
    ui->addToDoFrame->hide();
    ui->addToDoLineEdit->clear();
}

void ToDoAreaWidget::on_newToDoButton_clicked()
{
     ui->addToDoFrame->show();
}

void ToDoAreaWidget::on_deleteToDo_clicked(ToDoWidget* deletedToDo){
    for(QList<ToDoWidget*>::iterator it = toDoList.begin();it != toDoList.end(); ++it){
        if(*it == deletedToDo){
            delete deletedToDo;                 //delete ToDo widget
            toDoList.erase(it);                 //delete pointer on ToDo widget from list
            break;
        }
    }

    //debug
    if(toDoList.isEmpty()){
        qDebug() << "list of ToDo is empty";
    }else{
        qDebug() << "ToDo contain :" << toDoList.size();
    }
}


void ToDoAreaWidget::on_addToDoLineEdit_returnPressed()
{
    this->on_addToDoButton_clicked();
}
