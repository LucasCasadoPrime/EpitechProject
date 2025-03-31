/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGD07am-lucas.casado
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem
{
    class QuantumReactor {
        private:
            bool _stability;
        public:
            QuantumReactor();
            ~QuantumReactor();
            bool isStable();
            void setStability(bool); 
    };

    class Core {
        private:
            QuantumReactor * _coreReactor;
        public:
            Core(QuantumReactor *);
            ~Core();
            QuantumReactor *checkReactor();
            
    };
}

#endif /* !WARPSYSTEM_HPP_ */
