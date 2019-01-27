#pragma once
//change in mainwindow.h
#include <QMainWindow>

#include "ToDoAreaWidgets/TaskAreaWidget/TomorrowTaskAreaWidget/tomorrowtaskareawidget.h"
#include "ToDoAreaWidgets/TaskAreaWidget/SomeDayTaskAreaWidget/somedaytaskareawidget.h"
#include "ToDoAreaWidgets/IdeaAreaWidget/ideaareawidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void on_doTodayButton_clicked();

    void on_doTomorrowButton_clicked();

    void on_doSomeDayButton_clicked();

    void on_ideasButton_clicked();

private:
    Ui::MainWindow *ui;
    TaskAreaWidget * taskArea;
    TomorrowTaskAreaWidget * tomorrowTaskArea;
    SomeDayTaskAreaWidget * someDayTaskArea;
    IdeaAreaWidget * ideaArea;
};


