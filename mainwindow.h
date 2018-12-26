#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ToDoWidgets/TaskWidget/SomeDayTaskWidget/somedaytaskwidget.h"
#include "ToDoAreaWidgets/TaskAreaWidget/TomorrowTaskAreaWidget/tomorrowtaskareawidget.h"
#include "ToDoAreaWidgets/TaskAreaWidget/SomeDayTaskAreaWidget/somedaytaskareawidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_doTodayButton_clicked();

    void on_doTomorrowButton_clicked();

    void on_doSomeDayButton_clicked();

private:
    Ui::MainWindow *ui;
    TaskAreaWidget * taskArea;
    TomorrowTaskAreaWidget * tomorrowTaskArea;
    SomeDayTaskAreaWidget * someDayTaskArea;
};

#endif // MAINWINDOW_H
