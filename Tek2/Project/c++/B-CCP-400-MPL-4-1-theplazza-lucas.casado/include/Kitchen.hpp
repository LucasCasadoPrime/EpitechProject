/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-theplazza-lucas.casado
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include "include.hpp"
#include "ThreadPool.hpp"
#include "Client.hpp"

namespace plazza {
    class Kitchen {
        public:
            Kitchen(int, int);
            ~Kitchen();
            void init();
            void getData();
            void destroy();
            Client _client;
            ThreadPool _threadpool;
        protected:
        private:
            int _kitchenId;
            int _tomato;
            int _gruyere;
            int _ham;
            int _mushrooms;
            int _steak;
            int _eggplant;
            int  _goat_cheese;
    };
}

#endif /* !KITCHEN_HPP_ */
