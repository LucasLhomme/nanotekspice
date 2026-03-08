//
// Created by crabe on 13/02/2026.
//

#include "../../../include/components/advanced_components/comp_4801.hpp"
#include <array>
#include "../../../include/IComponent.hpp"

namespace nts {

    /**
     * \brief Helper to read the connected value for a given local pin.
     *
     * @param pin Pin number whose linked value is requested.
     * @return Tristate value from linked component or Undefined.
     */
    nts::Tristate Comp_4801::getVal(std::size_t pin)
    {
        if (_links.find(pin) == _links.end())
            return nts::Undefined;
        return _links[pin].first->compute(_links[pin].second);
    }

    /**
     * \brief Initialize 4801 memory arrays and buffers.
     */
    Comp_4801::Comp_4801() {
        _memory.resize(1024);
        for (auto& byte : _memory) {
            byte.fill(nts::Undefined);
        }
        _outputBuffer.fill(nts::Undefined);
    }

    /**
     * \brief Compute address from address pins; returns -1 if undefined.
     *
     * @return Integer address or -1 on undefined bits.
     */
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

    /**
     * \brief Handle read/write cycles and update output buffer accordingly.
     *
     * @param tick Simulation tick (unused).
     */
    void Comp_4801::simulate(std::size_t tick) {
        (void)tick;
        nts::Tristate ce = getVal(18); // Chip Enable
        nts::Tristate we = getVal(21); // Write Enable
        nts::Tristate oe = getVal(20); // Output Enable
        int addr = getAddress();

        static const std::vector<size_t> dataPins = {9, 10, 11, 13, 14, 15, 16, 17};

        if (ce == nts::False && we == nts::False) {
            if (addr >= 0 && addr < 1024) {
                for (size_t i = 0; i < 8; ++i) {
                    _memory[addr][i] = getVal(dataPins[i]);
                }
            }
        }

        if (ce == nts::False && we != nts::False && oe == nts::False) {
            if (addr >= 0 && addr < 1024) {
                _outputBuffer = _memory[addr];
            } else {
                _outputBuffer.fill(nts::Undefined);
            }
        } else {
            _outputBuffer.fill(nts::Undefined);
        }
    }

    /**
     * \brief Return the data bit present on the requested data pin.
     *
     * @param pin Pin number to query (data pins only).
     * @return Tristate value or Undefined.
     */
    nts::Tristate Comp_4801::compute(std::size_t pin) {
        static const std::vector<size_t> dataPins = {9, 10, 11, 13, 14, 15, 16, 17};

        for (size_t i = 0; i < dataPins.size(); ++i) {
            if (dataPins[i] == pin)
                return _outputBuffer[i];
        }
        return nts::Undefined;
    }
} // nts