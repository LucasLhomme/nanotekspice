//
// Created by crabe on 13/02/2026.
//

#include "../../../include/components/advanced_components/comp_4801.hpp"
#include <array>
#include "../../../include/IComponent.hpp"

namespace nts {

    Comp_4801::Comp_4801() {
        _memory.resize(1024);
        for (auto& byte : _memory) {
            byte.fill(nts::Undefined);
        }
    }

    nts::Tristate Comp_4801::getVal(std::size_t p)
    {
        if (_links.find(p) == _links.end())
            return nts::Undefined;
        return _links[p].first->compute(_links[p].second);
    }

    int Comp_4801::getAddress() {
        int address = 0;

        // A0=8 A1=7 A2=6 A3=5 A4=4 A5=3 A6=2 A7=1 A8=23 A9=22
        static const std::vector<size_t> addrPins = {8, 7, 6, 5, 4, 3, 2, 1, 23, 22};
        for (std::size_t i = 0; i < addrPins.size(); ++i) {
            nts::Tristate val = getVal(addrPins[i]);
            if (val == nts::Undefined)
                return -1;
            if (val == nts::True)
                address += (1 << i);
        }
        return address;
    }

    void Comp_4801::simulate(std::size_t tick) {
        (void)tick;
        nts::Tristate ce = getVal(18); // Chip Enable (CS)
        nts::Tristate we = getVal(21); // Write Enable
        int addr = getAddress();


        if (ce != nts::False || we != nts::False) {
            return;
        }
        if (addr < 0 || addr >= 1024)
            return;
        // write pin data: DQ0 to DQ7
        static const std::vector<size_t> dataPins = {9, 10, 11, 13, 14, 15, 16, 17};

        // store the data in memory
        for (size_t i = 0; i < 8; ++i) {
            _memory[addr][i] = getVal(dataPins[i]);
        }
    }

    nts::Tristate Comp_4801::compute(std::size_t pin) {
        static const std::vector<size_t> dataPins = {9, 10, 11, 13, 14, 15, 16, 17};
        nts::Tristate ce = getVal(18); // Chip Enable
        nts::Tristate oe = getVal(20); // Output Enable
        nts::Tristate we = getVal(21); // Write Enable
        int addr = getAddress();
        bool bitIndex = false;

        for (size_t i = 0; i < dataPins.size(); ++i) {
            if (dataPins[i] == pin) {
                bitIndex = true;
                break;
            }
        }
        if (bitIndex == false)
            return nts::Undefined;
        if (ce != nts::False || oe != nts::False || we == nts::False) {
            return nts::Undefined;
        }
        if (addr < 0 || addr >= 1024)
            return nts::Undefined;
        return _memory[addr][bitIndex];
    }
} // nts