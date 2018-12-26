#-------------------------------------------------
#
# Project created by QtCreator 2018-12-23T14:12:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToDo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    TodoWidgets/todowidget.cpp \
    ToDoWidgets/TaskWidget/taskwidget.cpp \
    ToDoWidgets/TaskWidget/Priority/priority.cpp \
    ToDoWidgets/TaskWidget/SomeDayTaskWidget/somedaytaskwidget.cpp \
    ToDoAreaWidgets/todoareawidget.cpp \
    ToDoAreaWidgets/TaskAreaWidget/taskareawidget.cpp \
    ToDoAreaWidgets/TaskAreaWidget/PriorityWidget/prioritywidget.cpp \
    ToDoAreaWidgets/TaskAreaWidget/TomorrowTaskAreaWidget/tomorrowtaskareawidget.cpp \
    ToDoAreaWidgets/TaskAreaWidget/SomeDayTaskAreaWidget/somedaytaskareawidget.cpp

HEADERS += \
        mainwindow.h \
    TodoWidgets/todowidget.h \
    ToDoWidgets/TaskWidget/taskwidget.h \
    ToDoWidgets/TaskWidget/Priority/priority.h \
    ToDoWidgets/TaskWidget/Priority/specialtypes.h \
    ToDoWidgets/TaskWidget/SomeDayTaskWidget/somedaytaskwidget.h \
    ToDoAreaWidgets/todoareawidget.h \
    ToDoAreaWidgets/TaskAreaWidget/taskareawidget.h \
    ToDoAreaWidgets/TaskAreaWidget/PriorityWidget/prioritywidget.h \
    ToDoAreaWidgets/TaskAreaWidget/TomorrowTaskAreaWidget/tomorrowtaskareawidget.h \
    ToDoAreaWidgets/TaskAreaWidget/SomeDayTaskAreaWidget/somedaytaskareawidget.h

FORMS += \
        mainwindow.ui \
    TodoWidgets/todowidget.ui \
    ToDoAreaWidgets/todoareawidget.ui \
    ToDoAreaWidgets/TaskAreaWidget/PriorityWidget/prioritywidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
