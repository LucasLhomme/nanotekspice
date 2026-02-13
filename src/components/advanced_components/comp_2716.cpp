//
// Created by crabe on 13/02/2026.
//

#include "../../../include/components/advanced_components/comp_2716.hpp"
#include <array>
#include "../../../include/IComponent.hpp"

namespace nts {

    Comp_2716::Comp_2716() {
        _memory.resize(2048);
        for (auto& byte : _memory) {
            byte.fill(nts::Undefined);
        }
    }


    int Comp_2716::getAddress() {
        int address = 0;

        // A0=8 A1=7 A2=6 A3=5 A4=4 A5=3 A6=2 A7=1 A8=23 A9=22 A10=19
        static const std::vector<size_t> addrPins = {8, 7, 6, 5, 4, 3, 2, 1, 23, 22, 19};
        for (std::size_t i = 0; i < addrPins.size(); ++i) {
            nts::Tristate val = getVal(addrPins[i]);
            if (val == nts::Undefined)
                return -1;
            if (val == nts::True)
                address += (1 << i);
        }
        return address;
    }

    void Comp_2716::simulate(std::size_t tick) {
        (void)tick;
    }

    nts::Tristate Comp_2716::compute(std::size_t pin) {
        static const std::vector<size_t> dataPins = {9, 10, 11, 13, 14, 15, 16, 17};
        nts::Tristate ce = getVal(18); // Chip Enable
        nts::Tristate oe = getVal(20); // Output Enable
        int addr = getAddress();
        int bitIndex = -1;

        for (size_t i = 0; i < dataPins.size(); ++i) {
            if (dataPins[i] == pin) {
                bitIndex = static_cast<int>(i);
                break;
            }
        }
        if (bitIndex == -1)
            return nts::Undefined;
        if (ce != nts::False || oe != nts::False) {
            return nts::Undefined;
        }
        if (addr < 0 || addr >= 2048)
            return nts::Undefined;
        return _memory[addr][bitIndex];
    }
} // nts