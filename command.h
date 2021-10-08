/*
Author: Ryan Wu
Content of this file: The header of the command class. It stores user's input, the output after
execution, and return status.
Date: Oct 5, 2021
*/

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

class command
{
private:
    std::string command_text;
    std::string result;
    int return_code;
public:
    command(std::string command);
    ~command();
    void execute();
    std::string get_command_text();
    std::string get_result();
    int get_return_code();
    void set_command_text(std::string command);
};

#endif // COMMAND_H
