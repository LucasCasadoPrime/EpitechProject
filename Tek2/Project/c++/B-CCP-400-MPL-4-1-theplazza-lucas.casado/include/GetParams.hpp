/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** getParams
*/

#ifndef GETPARAMS_HPP_
#define GETPARAMS_HPP_

#include "include.hpp"

namespace plazza 
{
    class GetParams
    {
        public:
            GetParams(int argc, char **argv);
            ~GetParams();
            int coefficient;
            int nbCooks;
            int timeRefill;
    };
    
}


#endif /* !GETPARAMS_HPP_ */
