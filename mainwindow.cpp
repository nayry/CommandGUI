/*
Author: Ryan Wu
Content of this file: The implementation of the application's GUI
Date: Oct 5, 2021
*/

#include <iostream>
#include <string>
#include <QMessageBox>
#include "mainwindow.h"
#include "command.h"


/*
Function name: MainWindow::MainWindow
Description: This the constructor of MainWindow class
Parameters: It takes (QWidget *parent) as the parameter. This parameter is predefined in the base class QMainWindow
Return: This function returns nothing
*/
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
    command_lable = new QLabel("Command: ", this);
    command_lable->setGeometry(QRect(QPoint(50, 20), QSize(100, 30)));

    execute_button = new QPushButton("Execute", this);
    execute_button->setGeometry(QRect(QPoint(300, 20), QSize(100, 30)));

    command_input = new QLineEdit("", this);
    command_input->setGeometry(QRect(QPoint(130, 20), QSize(150, 30)));

    output_lable = new QLabel("Output: ", this);
    output_lable->setGeometry(QRect(QPoint(50, 60), QSize(100, 30)));

    output = new QTextEdit(this);
    output->setGeometry(QRect(QPoint(50, 100), QSize(350, 180)));
    output->setReadOnly(true);

    status_lable = new QLabel("Exit Status: ", this);
    status_lable->setGeometry(QRect(QPoint(50, 290), QSize(100, 30)));

    history_lable = new QLabel("History: ", this);
    history_lable->setGeometry(QRect(QPoint(50, 350), QSize(100, 30)));

    command_list = new QListWidget(this);
    command_list->setGeometry(QRect(QPoint(50, 400), QSize(350, 300)));

    // Connect button signal to appropriate slot
    connect(execute_button, &QPushButton::pressed, this, &MainWindow::execute);
    connect(command_input, &QLineEdit::returnPressed, this,  &MainWindow::execute);
    connect(command_list, &QListWidget::itemDoubleClicked, this, &MainWindow::showHistory);
}


/*
Function name: MainWindow::~MainWindow
Description: This the destructor of MainWindow class. It deletes all dynamically allocated memorry
Parameters: This function does not have parameters
Return: This function returns nothing
*/
MainWindow::~MainWindow(){
    delete execute_button;
    delete command_input;
    delete output;
    delete command_list;
    delete command_lable;
    delete output_lable;
    delete status_lable;
    delete history_lable;
    for(command* Command : commands)
      delete Command;
}


/*
Function name: MainWindow::execute
Description: This function executes user's command input and stores the output string and status code
Parameters: This function does not have parameters
Return: This function returns nothing
*/
void MainWindow::execute()
{
    if (!command_input->displayText().toStdString().empty()){
        command *Command =  new command(command_input->displayText().toStdString());
        commands.push_back(Command);

        // produce the appropriate text to display on command history list
        std::string history_text = std::to_string(commands.size());
        history_text += ". ";
        history_text += command_input->displayText().toStdString();
        history_text += " (";
        history_text += std::to_string(Command->get_return_code());
        history_text += ")";

        command_list->addItem(QString::fromStdString(history_text));

        if (Command->get_return_code() == 0) {
            status_lable->setText("Exit Status: 0");
        } else {
            status_lable->setText("Exit Status: -1");
        }

        output->setText(QString::fromStdString(Command->get_result()));
    }
}


/*
Function name: MainWindow::showHistory
Description: This function pops up a new window showing information of a previously executed command.
Parameters: This function does not have parameters
Return: This function returns nothing
*/
void MainWindow::showHistory(){
    // produce the appropriate text to display on history pop up window
    std::string display_history = "Command Input: ";
    display_history += commands[command_list->currentRow()]->get_command_text();
    display_history += "\n";
    display_history += "Command Status: ";
    display_history += std::to_string(commands[command_list->currentRow()]->get_return_code());
    display_history += "\n";
    display_history += "Command Output:\n";
    display_history += commands[command_list->currentRow()]->get_result();

    QMessageBox::about(this, "Command History", QString::fromStdString(display_history));
}
