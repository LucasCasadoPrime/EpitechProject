/*
** EPITECH PROJECT, 2022
** B-PDG-300-MPL-3-1-PDGRUSH3-lucas.casado
** File description:
** ModuleCpu
*/

#ifndef MODULECPU_HPP_
#define MODULECPU_HPP_

#include "IMonitorModule.hpp"


class ModuleCpu {
    public:
        ModuleCpu();
        ~ModuleCpu();

        void setCpu();
        float sendCpu(size_t cpuIndex) const;
        const size_t getCpuNbr() const;
        const long long getTotal() const;

    protected:
        const size_t _cpuNumber;
        std::vector<long long> _cpuUsage;
        std::vector<float> _cpuRes;
};

#endif /* !MODULECPU_HPP_ */
