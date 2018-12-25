#pragma once

#include <QWidget>
#include <QString>
#include <QDebug>

namespace Ui {
class ToDoWidget;
}

class ToDoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ToDoWidget(QWidget *parent = nullptr);
    explicit ToDoWidget(const ToDoWidget& other);
    ToDoWidget& operator=(const ToDoWidget& other);
    ~ToDoWidget();

    void setText(QString note);
    QString getText() const;

signals:
    void deleteToDo(ToDoWidget * deletedToDo);

private slots:
    void on_compliteToDoCheckBox_clicked(bool checked);
    void on_deleteToDoButton_clicked();

protected:
    Ui::ToDoWidget *ui;
};

inline QDataStream& operator<<(QDataStream &out, const ToDoWidget& task){

    out << task.getText();

    return  out;
}

inline QDataStream& operator>>(QDataStream &in, ToDoWidget& task){
    QString note;
    in >> note;
    task.setText(note);

    return  in;
}
