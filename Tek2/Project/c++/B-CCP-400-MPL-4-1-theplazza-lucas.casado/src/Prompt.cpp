/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** Prompt
*/

#include "../include/Prompt.hpp"

//regina XXL x2; fantasia M x3; margarita S x1
plazza::Prompt::Prompt() {}

plazza::Prompt::~Prompt() {}

bool isnum(std::string str)
{
    for (int i = 0; i <str.size(); i++) {
        if(isdigit(str[i]))
            return(true);
    }
    return(false);
}

std::vector<std::string> plazza::Prompt::split(std::string phrase, std::string delimiter)
{
    std::vector<std::string> list;
    size_t pos = 0;
    std::string token;
    while ((pos = phrase.find(delimiter)) != std::string::npos) {
        token = phrase.substr(0, pos);
        list.push_back(token);
        phrase.erase(0, pos + delimiter.length());
    }
    list.push_back(phrase);
    return list;
}

std::vector<std::vector<std::string>> plazza::Prompt::tab_manager(std::vector<std::string> tab_pizza)
{
    std::vector<std::vector<std::string>> ingredients;
    std::vector<std::string> ingredient;
    for (int i = 0; i < tab_pizza.size();i++) {
        ingredient = split(tab_pizza[i]," ");
        ingredients.push_back(ingredient);
    }
    return ingredients;
}


std::string plazza::Prompt::Command_Writer(std::string command_s, int command_count)
{
    std::string s = std::to_string(command_count);
    std::string q;
    std::string stk;
    std::string type;
    std::string size;
    std::string quantity;

    if (command_s == "regina")
        type = "T1";
    if (command_s == "margarita")
        type = "T2";
    if (command_s == "americana")
        type = "T4";
    if (command_s == "fantasia")
        type = "T8";

    if (command_s == "S")
        size = "S1";
    if (command_s == "M")
        size = "S2";
    if (command_s == "L")
        size =  "S4";
    if (command_s == "XL") 
        size =  "S8";
    if (command_s == "XXL") 
        size =  "S16";
    if (isnum(command_s) == true){
        command_s.replace(0,1,"Q");
       quantity = command_s +":";
    }
    stk += type; 
    stk += size;
    stk += quantity;
    return (stk);
}

std::string plazza::Prompt::encryptions(std::vector<std::vector<std::string>> command, int command_count)
{
    std::string cmd;
    for (int i = 0; i < command.size();i++) {
        for(int j = 0; j < command[i].size();j++)
            cmd += Command_Writer(command[i][j], command_count);
    }
    cmd[cmd.size()-1] = '\0';
    return(cmd);
}

void plazza::Prompt::start()
{
    int command_count = 0;
    Prompt p;
    std::string input;
    std::vector<std::string> tab_input;
    std::vector<std::vector<std::string>> command;
    while(1) {
        plazza::Socket::writeFD(1, ">");
        std::getline (std::cin, input);
        if (input == "status" || input == "exit") {
            std::cout << "special input found" << std::endl;
            p._client.sendData(input);
            if (input == "exit") {
                plazza::Socket::myExit(0);
            }
        } else  {
            tab_input = p.split(input,"; ");
            command = p.tab_manager(tab_input);
            command_count++;
            p._client.sendData(p.encryptions(command, command_count));
        }
    }
}
