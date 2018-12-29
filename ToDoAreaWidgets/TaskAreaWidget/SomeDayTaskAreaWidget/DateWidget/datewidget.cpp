#include "datewidget.h"
#include "ui_datewidget.h"
#include <QDebug>

DateWidget::DateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DateWidget)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
}

DateWidget::~DateWidget()
{
    delete ui;
}

QDate DateWidget::getComplitionDate()
{
    return ui->dateEdit->date();
}
