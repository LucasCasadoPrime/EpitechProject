/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** KitchenData
*/

#ifndef KITCHENDATA_HPP_
    #define KITCHENDATA_HPP_
    #include "include.hpp"

namespace plazza {
    class KitchenData {
        public:
            KitchenData(int id);
            ~KitchenData();
            void printInfo();
        private:
            std::string taskList;
            int _id;
            int _tomato;
            int _gruyere;
            int _ham;
            int _mushrooms;
            int _steak;
            int _eggplant;
            int  _goat_cheese;
    };
}

#endif /* !KITCHENDATA_HPP_ */
