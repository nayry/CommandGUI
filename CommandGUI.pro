# Author: Ryan Wu
# This file is to connect/build all the files and resources of the application
# Date: Oct 5, 2021

QT       += core widgets
TARGET = CommandGUI
TEMPLATE = app
SOURCES += main.cpp mainwindow.cpp \
    command.cpp
HEADERS += mainwindow.h \
    command.h
INCLUDEPATH += "/opt/homebrew/Cellar/boost/1.76.0/include"
