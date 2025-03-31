/*
** EPITECH PROJECT, 2022
** B-OOP-400-MPL-4-1-arcade-lucas.casado
** File description:
** error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>
#include <exception>

namespace arcade {
    class Exception : virtual public std::exception {
        public:
            Exception(const std::string &);
            virtual ~Exception() throw() {};
            virtual const char *what() const throw();
        protected:
            std::string _what;
    };
}

#endif /* !ERROR_HPP_ */