/*
Author: Ryan Wu
Content of this file: The implementation of the command class. It stores user's input, the output after
execution, and return status.
Date: Oct 5, 2021
*/

#include <iostream>
#include <exception>
#include <boost/process.hpp>
#include "command.h"

using namespace boost::process;


/*
Function name: command::command
Description: This is the constructor of command class
Parameters: This function takes the user inputted command as parameter and stores it as a data member
Return: This function returns nothing
*/
command::command(std::string command)
{
    this->command_text = command;
    this->result = "";
    this->return_code = 0;
    this->execute();
}


/*
Function name: command::~command
Description: This is the destructor of command class
Parameters: This function does not have parameter
Return: This function returns nothing
*/
command::~command(){}


/*
Function name: command::execute
Description: This function executes the command and stores the output and status code
Parameters: This function does not have parameter
Return: This function returns nothing
*/
void command::execute(){
    try {
        ipstream pipe_stream;
        child c(this->get_command_text(), (std_out & std_err) > pipe_stream);

        std::string line;

        while (pipe_stream && std::getline(pipe_stream, line) && !line.empty()){
            this->result += line;
            this->result += "\n";
        }
    }  catch (std::exception& e) {
        this->result = e.what();
        this->return_code = -1;
    }
}


/*
Function name: command::get_command_text
Description: This is the getter of command_text data member
Parameters: This function does not have parameter
Return: This function returns nothing
*/
std::string command::get_command_text(){
    return this->command_text;
}


/*
Function name: command::get_result
Description: This is the getter of result data member
Parameters: This function does not have parameter
Return: This function returns nothing
*/
std::string command::get_result(){
    return this->result;
}


/*
Function name: command::get_return_code
Description: This is the getter of return_code data member
Parameters: This function does not have parameter
Return: This function returns nothing
*/
int command::get_return_code(){
    return this->return_code;
}


/*
Function name: command::set_command_text
Description: This is the setter of command_text data member
Parameters: This function takes a string as parameter and save it to command_text data member
Return: This function returns nothing
*/
void command::set_command_text(std::string command){
    this->command_text = command;
}
