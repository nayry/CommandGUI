/*
Author: Ryan Wu
Content of this file: Main function of the application
Date: Oct 5, 2021
*/

#include <QApplication>
#include <iostream>
#include "mainwindow.h"


/*
Function name: main
Description: This is the main function of the application
Parameters: This function takes (int argc, char *argv[]) as parameters, which are required for QApplication class
Return: This function returns the exit code of QApplication::exec()
*/
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.showMaximized();
    return app.exec();
}
