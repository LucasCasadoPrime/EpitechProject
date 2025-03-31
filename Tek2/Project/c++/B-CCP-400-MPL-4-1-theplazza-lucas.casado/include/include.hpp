/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-panoramix-lucas.casado
** File description:
** include
*/

#ifndef MY_INCLUDE_H_
    #define MY_INCLUDE_H_

    // lib include //
    #include <iostream>
    #include <string>
    #include <fstream>
    #include <vector>
    #include <algorithm>
    #include <thread>
    #include <mutex>
    #include <memory>
    #include <chrono>
    #include <exception>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <sys/types.h>
    #include <netdb.h>
    #include <unistd.h>
    #include <sys/ipc.h>
    #include <sys/shm.h>
    #include <arpa/inet.h>
    #include <ctype.h>
    #include <sys/types.h>
    #include <stdlib.h>
    #include <string.h>

    /* function */

    namespace plazza {
        enum PizzaType {
            Regina = 1,
            Margarita = 2,
            Americana = 4,
            Fantasia = 8
        };
        enum PizzaSize {
            S = 1,
            M = 2,
            L = 4,
            XL = 8,
            XXL = 16
        };
    }

#endif /* !MY_INCLUDE_H_ */
