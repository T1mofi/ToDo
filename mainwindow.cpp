#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    taskArea = new TaskAreaWidget();
    taskArea->readToDoFromfile();
    taskArea->hide();
    ui->centralWidgetLayout->addWidget(taskArea);

    tomorrowTaskArea = new TomorrowTaskAreaWidget();
    QObject::connect(tomorrowTaskArea,SIGNAL(moveTask(TaskWidget)),
                     taskArea,SLOT(addTaskFromOtherArea(TaskWidget)));
    tomorrowTaskArea->readToDoFromfile();
    tomorrowTaskArea->hide();
    ui->centralWidgetLayout->addWidget(tomorrowTaskArea);


}

MainWindow::~MainWindow()
{
    delete tomorrowTaskArea;
    delete taskArea;
    delete ui;
}

void MainWindow::on_doTodayButton_clicked()
{
    taskArea->show();
}

void MainWindow::on_doTomorrowButton_clicked()
{
    tomorrowTaskArea->show();
}
