#include "somedaytaskwidget.h"
#include "ui_todowidget.h"


SomeDayTaskWidget::SomeDayTaskWidget(const QDate& newComplitionDate) :
    complitionDate(newComplitionDate), dateLabel(new QLabel)
{
    dateLabel->setText(newComplitionDate.toString("dd/MM/yy"));
    dateLabel->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    ui->additionInformationLayout->addWidget(dateLabel);
    dateLabel->show();
}
