// old

#include "mainwindow.h"
#include <QApplication>

#include <QFile>
#include <QDataStream>
#include <QDate>
#include <QLabel>

//#include "ToDoAreaWidgets/todoareawidget.h"
//#include "ToDoAreaWidgets/TaskAreaWidget/taskareawidget.h"
#include "ToDoAreaWidgets/TaskAreaWidget/TomorrowTaskAreaWidget/tomorrowtaskareawidget.h"

//#include "ToDoWidgets/todowidget.h"
//#include "ToDoWidgets/TaskWidget/taskwidget.h"
#include "ToDoWidgets/TaskWidget/SomeDayTaskWidget/somedaytaskwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
            qDebug() << "(int)(QDate::currentDate().daysTo(tempTask->getComplitionDate()))";

//    TaskAreaWidget area("task.bin");
//    area.show();

//    QDate date1(18, 12, 31);
//    QDate date2(18, 12, 30);
//    qDebug() << "Осталось " << date1.daysTo(date2);

//    TaskWidget task;
//    task.setText("text");
//    task.show();


{
//    QDate tempDate(2018,12,28);

//    SomeDayTaskWidget task(tempDate);
//    task.setText("task With date");
//    task.show();

//            QFile file("somedayTasks.bin");
//            if(file.open(QIODevice::WriteOnly))
//            {
//                QDataStream stream(&file);
//                stream.setVersion(QDataStream::Qt_4_5);

//                    stream << task;                                                  //add try cath

//                if (stream.status() != QDataStream::Ok) {
//                    qDebug() << "Ошибка записи";
//                }
//            }
//            else
//            {
//                qDebug() << "error file open";
//            }
//            file.close();


//    ///////////////////////////////////////////////////////////////////////
//        SomeDayTaskWidget task2;
//        task2.show();
//                QFile fileIn("somedayTasks.bin");
//                if(fileIn.open(QIODevice::ReadOnly))
//                {
//                    QDataStream stream(&fileIn);
//                    stream.setVersion(QDataStream::Qt_4_5);

//                        stream >> task2;
//                }
//                else
//                {
//                    qDebug() << "error file open";
//                }                                                                                                  //else throw
//                fileIn.close();
}


{
//    ToDoWidget toDo;
//    toDo.setText("just todo");
//    toDo.show();

//        QFile file("toDo.bin");
//        if(file.open(QIODevice::WriteOnly))
//        {
//            QDataStream stream(&file);
//            stream.setVersion(QDataStream::Qt_4_5);

//                stream << toDo;                                                  //add try cath

//            if (stream.status() != QDataStream::Ok) {
//                qDebug() << "Ошибка записи";
//            }
//        }
//        else
//        {
//            qDebug() << "error file open";
//        }
//        file.close();

///////////////////////////////////////////////////////////////////////
//        ToDoWidget toDo2;

//            QFile fileIn("toDo.bin");
//            if(fileIn.open(QIODevice::ReadOnly))
//            {
//                QDataStream stream(&fileIn);
//                stream.setVersion(QDataStream::Qt_4_5);

//                    stream >> toDo2;
//            }
//            else
//            {
//                qDebug() << "error file open";
//            }                                                                                                  //else throw
//            fileIn.close();

//        toDo2.show();
}


{
//    TaskWidget task(veryImportant);
//    task.setText("important task");
//    task.show();

//        QFile file("tasks.bin");
//        if(file.open(QIODevice::WriteOnly))
//        {
//            QDataStream stream(&file);
//            stream.setVersion(QDataStream::Qt_4_5);

//                stream << task;                                                  //add try cath

//            if (stream.status() != QDataStream::Ok) {
//                qDebug() << "Ошибка записи";
//            }
//        }
//        else
//        {
//            qDebug() << "error file open";
//        }
//        file.close();


///////////////////////////////////////////////////////////////////////
//    TaskWidget task2;

//            QFile fileIn("tasks.bin");
//            if(fileIn.open(QIODevice::ReadOnly))
//            {
//                QDataStream stream(&fileIn);
//                stream.setVersion(QDataStream::Qt_4_5);

//                    stream >> task2;
//            }
//            else
//            {
//                qDebug() << "error file open";
//            }                                                                                                  //else throw
//            fileIn.close();

//    task2.show();
}


{
//    QDate creationDate = QDate::currentDate();
//    qDebug() << creationDate.toString();

//            QFile file("date.bin");
//            if(file.open(QIODevice::WriteOnly))
//            {
//                QDataStream stream(&file);
//                stream.setVersion(QDataStream::Qt_4_5);


//                stream << creationDate;

//                if (stream.status() != QDataStream::Ok) {
//                    qDebug() << "Ошибка записи";
//                }
//            }
//            else
//            {
//                qDebug() << "error file open";
//            }
//            file.close();


//    QDate tempDate;
//    qDebug() << tempDate.toString();

//                QFile fileIn("date.bin");
//                if(fileIn.open(QIODevice::ReadOnly))
//                {
//                    QDataStream stream(&fileIn);
//                    stream.setVersion(QDataStream::Qt_4_5);

//                    stream >> tempDate;
//                }
//                else
//                {
//                    qDebug() << "error file open";
//                }                                                                                                  //else throw

//                fileIn.close();

//    qDebug() << tempDate.toString();

}

    return a.exec();
}
