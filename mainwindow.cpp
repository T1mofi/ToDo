#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow() : ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    taskArea = new TaskAreaWidget;
    taskArea->readToDoFromfile();
    taskArea->hide();
    ui->centralWidgetLayout->addWidget(taskArea);

    tomorrowTaskArea = new TomorrowTaskAreaWidget;
    QObject::connect(tomorrowTaskArea,SIGNAL(moveTask(TaskWidget)),
                     taskArea,SLOT(addTaskFromOtherArea(TaskWidget)));
    tomorrowTaskArea->readToDoFromfile();
    tomorrowTaskArea->hide();
    ui->centralWidgetLayout->addWidget(tomorrowTaskArea);

    someDayTaskArea = new SomeDayTaskAreaWidget;
    QObject::connect(someDayTaskArea,SIGNAL(moveTaskToToday(TaskWidget)),
                     taskArea,SLOT(addTaskFromOtherArea(TaskWidget)));
    QObject::connect(someDayTaskArea,SIGNAL(moveTaskToTommorow(TaskWidget)),
                     tomorrowTaskArea,SLOT(addTaskFromSomeDayArea(TaskWidget)));
    someDayTaskArea->readToDoFromfile();
    someDayTaskArea->hide();
    ui->centralWidgetLayout->addWidget(someDayTaskArea);

    ideaArea = new IdeaAreaWidget;
    ideaArea->readToDoFromfile();
    ideaArea->hide();
    ui->centralWidgetLayout->addWidget(ideaArea);
}

MainWindow::~MainWindow()
{
    delete someDayTaskArea;
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

void MainWindow::on_doSomeDayButton_clicked()
{
        someDayTaskArea->show();
}

void MainWindow::on_ideasButton_clicked()
{
    ideaArea->show();
}
