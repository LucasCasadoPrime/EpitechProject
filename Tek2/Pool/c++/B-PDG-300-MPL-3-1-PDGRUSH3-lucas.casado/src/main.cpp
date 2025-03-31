/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGRUSH3-lucas.casado
** File description:
** main
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <ncurses.h>
#include "ModuleOS.hpp"
#include "ModuleUser.hpp"
#include "ModuleDate.hpp"
#include "ModuleCpu.hpp"
#include "ModuleNetwork.hpp"
#include "ModuleRam.hpp"
#include "IMonitorModule.hpp"
#include <string.h>
#include "sfml.hpp"

typedef struct gereral_s {
    ModuleOs _os;
    ModuleUser _user;
    ModuleDate _date;
    ModuleCpu _cpu;
    ModuleNetwork _net;
    ModuleRam _ram;
} general_t;

void refreshModule(general_t *Monitor) {
    Monitor->_cpu.setCpu();
    Monitor->_date.setDate();
    Monitor->_net.setData();
    Monitor->_ram.setData();
}

WINDOW *printBoxOS(general_t Monitor, WINDOW *BoxOS) {
    BoxOS = subwin(stdscr, LINES / 5, COLS / 5, 0, 0);
    box(BoxOS, ACS_VLINE, ACS_HLINE);
    mvwprintw(BoxOS, 1, 1, "Os: ");
    mvwprintw(BoxOS, 1, 5, Monitor._os.sendOSName().c_str());
    mvwprintw(BoxOS, 2, 1, "Kernel: ");
    mvwprintw(BoxOS, 2, 9, Monitor._os.sendKernelVersion().c_str());
    return (BoxOS);
}

WINDOW *printBoxUsr(general_t Monitor, WINDOW *BoxUsr) {
    BoxUsr = subwin(stdscr, LINES / 5, COLS / 5, 0, COLS / 5);
    box(BoxUsr, ACS_VLINE, ACS_HLINE);
    mvwprintw(BoxUsr, 1, 1, "Username: ");
    mvwprintw(BoxUsr, 1, 11, Monitor._user.getUsername().c_str());
    mvwprintw(BoxUsr, 2, 1, "Hostname: ");
    mvwprintw(BoxUsr, 2, 11, Monitor._user.getHostname().c_str()); 
    return (BoxUsr);  
}

WINDOW *printBoxDate(general_t Monitor, WINDOW *BoxDate) {
    BoxDate = subwin(stdscr, LINES / 6, COLS / 6, 0, COLS / 5 * 2);
    box(BoxDate, ACS_VLINE, ACS_HLINE);
    mvwprintw(BoxDate, 1, 1, "Date: ");
    mvwprintw(BoxDate, 1, 7, Monitor._date.sendDate().c_str());
    return (BoxDate);
}

WINDOW *printBoxCpu(general_t Monitor, WINDOW *BoxCpu) {
    int i = 0;
    BoxCpu = subwin(stdscr, Monitor._cpu.getCpuNbr() + 5, COLS / 4, LINES / 5, 0);
    box(BoxCpu, ACS_VLINE, ACS_HLINE);
    mvwprintw(BoxCpu, 1, 1, "CPU: ");
    for (i = 0; i < Monitor._cpu.getCpuNbr(); i++) {
        mvwprintw(BoxCpu, i + 2, 6, "CPU[%d]: ", i + 1);
        mvwprintw(BoxCpu, i + 2, 16, "%f%%", Monitor._cpu.sendCpu(i));
    }
    mvwprintw(BoxCpu, i + 3, 1, "Total CPU Usage: %f %%", Monitor._cpu.getTotal());
    return (BoxCpu);
}

WINDOW *printBoxRam(general_t Monitor, WINDOW *BoxRam) {
    BoxRam = subwin(stdscr, 11, COLS / 3, LINES / 5, COLS / 4);
    box(BoxRam, ACS_VLINE, ACS_HLINE);
    mvwprintw(BoxRam, 1, 1, "RAM: ");
    mvwprintw(BoxRam, 2, 1, "   RAM usage: %s -> %f%%", Monitor._ram.SendRamUsed().c_str(), (std::stof(Monitor._ram.SendRamUsed()) / std::stof(Monitor._ram.SendRamTotal()) * 100));
    mvwprintw(BoxRam, 3, 1, "   Free RAM: %s -> %f%%", Monitor._ram.SendRamAvailable().c_str(), (std::stof(Monitor._ram.SendRamAvailable()) / std::stof(Monitor._ram.SendRamTotal()) * 100));
    mvwprintw(BoxRam, 4, 1, "   Total RAM: %s", Monitor._ram.SendRamTotal().c_str());
    mvwprintw(BoxRam, 6, 1, "Swap: ");
    mvwprintw(BoxRam, 7, 1, "   Swap usage: %s -> %f%%", Monitor._ram.SendSwapUsed().c_str(), (std::stof(Monitor._ram.SendSwapUsed()) / std::stof(Monitor._ram.SendSwapTotal()) * 100));
    mvwprintw(BoxRam, 8, 1, "   Free Swap: %s -> %f%%", Monitor._ram.SendswapAvailable().c_str(), (std::stof(Monitor._ram.SendswapAvailable()) / std::stof(Monitor._ram.SendSwapTotal()) * 100));
    mvwprintw(BoxRam, 9, 1, "   Total Swap: %s", Monitor._ram.SendSwapTotal().c_str());
    return (BoxRam);
}

WINDOW *printBoxNet(general_t Monitor, WINDOW *BoxNet) {
    BoxNet = subwin(stdscr, 5, COLS / 4, LINES / 2.37, 0);
    box(BoxNet, ACS_VLINE, ACS_HLINE);
    mvwprintw(BoxNet, 1, 1, "Network usage:");
    mvwprintw(BoxNet, 2, 1, " Download: %lld bytes -> %lldmb",Monitor._net.sendDownload(), Monitor._net.sendDownload() / (1024 * 1024));
    mvwprintw(BoxNet, 3, 1, " Upload: %lld bytes -> %lldmb", Monitor._net.sendUpload(), Monitor._net.sendUpload() / (1024 * 1024));
    return (BoxNet);
}

void textualLaunch(general_t Monitor) {
    WINDOW *BoxOS;
    WINDOW *BoxUsr;
    WINDOW *BoxDate;
    WINDOW *BoxCpu;
    WINDOW *BoxRam;
    WINDOW *BoxNet;
    initscr();
    keypad(stdscr, false);
    curs_set(0);
    noecho();
    while(true) {
        clear();
        refreshModule(&Monitor);
        BoxOS = printBoxOS(Monitor, BoxOS);
        BoxUsr = printBoxUsr(Monitor, BoxUsr);
        BoxDate = printBoxDate(Monitor, BoxDate);
        BoxCpu = printBoxCpu(Monitor, BoxCpu);
        BoxRam = printBoxRam(Monitor, BoxRam);
        BoxNet = printBoxNet(Monitor, BoxNet);
        usleep(100000);
        refresh();
    }
    endwin();
    free(BoxOS);
}

void graphicalLaunch() 
{
    sfml graphic;
    graphic.mainWindow();
}

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "MyGKrellm" << std::endl;
        std::cout << "      -t for text mode" << std::endl;
        std::cout << "      -g for graphics mode" << std::endl;
        return (0);
    }
    general_t Monitor;
    if (av[1][0] == '-' && av[1][1] == 'g') {
        std::cout << "Graphical" << std::endl;
        graphicalLaunch();
    } else if (av[1][0] == '-' && av[1][1] == 't') {
        std::cout << "Text" << std::endl;
        textualLaunch(Monitor);
    } else {
        std::cout << "MyGKrellm" << std::endl;
        std::cout << "      -t for text mode" << std::endl;
        std::cout << "      -g for graphics mode" << std::endl;
        return (0);
    }
    return (0);
}