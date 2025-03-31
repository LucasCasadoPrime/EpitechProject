/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD10pm-lucas.casado
** File description:
** WaterReclaimer
*/

#include <cstddef>
#include "BaseComponent.hpp"

class WaterReclaimer : public BaseComponent
{
    public:
        WaterReclaimer();
        virtual ~WaterReclaimer() {}

        void start();
        void generateWater();
        void useWater(int water);

    private:
        int _water;
        bool _started;
};
