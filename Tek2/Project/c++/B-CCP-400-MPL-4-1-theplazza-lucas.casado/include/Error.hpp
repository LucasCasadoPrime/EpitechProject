/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** Error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_

    #include "include.hpp"

namespace plazza {
    class Error : public virtual std::exception {
            private:
                std::string _msg;
            public:
                Error(std::string msg);
                ~Error(void);
                const char *what(void);
        };
}

#endif /* !ERROR_HPP_ */
