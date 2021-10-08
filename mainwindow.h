/*
Author: Ryan Wu
Content of this file: The header of the application's GUI
Date: Oct 5, 2021
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QString>
#include <QListWidget>
#include <QLabel>
#include <vector>
#include "command.h"

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
    void execute();
    void showHistory();
private:
    QPushButton *execute_button;
    QLineEdit *command_input;
    QTextEdit *output;
    QListWidget *command_list;
    QLabel *command_lable;
    QLabel *output_lable;
    QLabel *status_lable;
    QLabel *history_lable;
    std::vector<command*> commands;
};

#endif // MAINWINDOW_H
