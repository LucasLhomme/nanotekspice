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
        _outputBuffer.fill(nts::Undefined);
    }

    int Comp_4801::getAddress() {
        int address = 0;
        static const std::vector<size_t> addrPins = {8, 7, 6, 5, 4, 3, 2, 1, 23, 22};
        for (std::size_t i = 0; i < addrPins.size(); ++i) {
            nts::Tristate val = getLinkValue(addrPins[i]);
            if (val == nts::Undefined)
                return -1;
            if (val == nts::True)
                address += (1 << i);
        }
        return address;
    }

    void Comp_4801::simulate(std::size_t tick) {
        (void)tick;
        nts::Tristate ce = getLinkValue(18);
        nts::Tristate we = getLinkValue(21);
        nts::Tristate oe = getLinkValue(20);
        int addr = getAddress();

        static const std::vector<size_t> dataPins = {9, 10, 11, 13, 14, 15, 16, 17};

        if (ce == nts::False) {
            if (we == nts::False) {
                if (addr >= 0 && addr < 1024) {
                    for (size_t i = 0; i < dataPins.size(); ++i)
                        _memory[addr][i] = getLinkValue(dataPins[i]);
                }
                _outputBuffer.fill(nts::Undefined);
            } else if (oe == nts::False) {
                if (addr >= 0 && addr < 1024)
                    _outputBuffer = _memory[addr];
                else
                    _outputBuffer.fill(nts::Undefined);
            } else {
                _outputBuffer.fill(nts::Undefined);
            }
        } else {
            _outputBuffer.fill(nts::Undefined);
        }
    }

    nts::Tristate Comp_4801::compute(std::size_t pin) {
        static const std::vector<size_t> dataPins = {9, 10, 11, 13, 14, 15, 16, 17};

        for (size_t i = 0; i < dataPins.size(); ++i) {
            if (dataPins[i] == pin)
                return _outputBuffer[i];
        }
        return nts::Undefined;
    }
}