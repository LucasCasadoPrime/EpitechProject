/*
** EPITECH PROJECT, 2021
** sn0w
** File description:
** Box.hpp
*/

#ifndef BOMBERMAN_BOX_HPP
#define BOMBERMAN_BOX_HPP

#include "Raylib.hpp"

#if _WIN32
namespace Bomberman{
    namespace Entities {
        class Box {
        public:
            Box(Vector3 position, int id);
            ~Box();
            Raylib::Models::ModelB* getModel();
            Vector3 getPosition();
            int getId(void);

        private:
            int _id;
            Vector3 _position;
            Raylib::Models::ModelB* _model;
        };
    }
}
#else
namespace Bomberman::Entities {
    class Box {
    public:
        Box(Vector3 position, int id);
        ~Box();
        Raylib::Models::ModelB* getModel();
        Vector3 getPosition();
        int getId(void);

    private:
        int _id;
        Vector3 _position;
        Raylib::Models::ModelB* _model;
    };
}
#endif

#endif
