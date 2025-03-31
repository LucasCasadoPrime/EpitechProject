/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-clement.ozor
** File description:
** SaveAndLoad
*/

#ifndef SAVEANDLOAD_HPP_
#define SAVEANDLOAD_HPP_

#include "Essentials.hpp"
#include "Entities/Entities.hpp"
#include "PowerUp/PowerUp.hpp"

namespace Bomberman {
    class SaveAndLoad {
    public:
        SaveAndLoad();
        ~SaveAndLoad();
        void save(Entities::Entities entitiesGame, PowerUp::PowerUp powerUps);
        void load(Entities::Entities* entitiesGame, PowerUp::PowerUp* powerUps);
        bool isSaved();

    private:
        float roundFloat(float value, int precision = 1);
    };
}
#endif /* !SAVEANDLOAD_HPP_ */
