/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD11-lucas.casado
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"

class Toy {
    public:
        enum ToyType {BASIC_TOY, ALIEN};
        Toy();
        Toy(ToyType, std::string const &, std::string const &);
        Toy(Toy const &);
        ToyType getType() const;
        std::string getName() const;
        void setName(std::string);
        std::string getAscii() const;
        bool setAscii(std::string);
        ~Toy();

    protected:
        ToyType _type;
        std::string _name;
        Picture _picture;
};

#endif /* !TOY_HPP_ */
