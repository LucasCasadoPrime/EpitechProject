/*
** EPITECH PROJECT, 2022
** C++
** File description:
** sickkoala
*/


#ifndef SICKKOALA_HPP_
    #define SICKKOALA_HPP_
    
    #include <string>
    #include <cstring>
    #include <iostream>

    class SickKoala {
        public:
            SickKoala(std::string);
            ~SickKoala();
            void poke();
            bool takeDrug(std::string);
            void overDrive(std::string);
            std::string getName();
        private:
            std::string name;
    };

#endif /* !SICKKOALA_HPP_ */
