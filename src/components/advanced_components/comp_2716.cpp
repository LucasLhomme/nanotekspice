//
// Created by crabe on 13/02/2026.
//

#include "../../../include/components/advanced_components/comp_2716.hpp"
#include <array>
#include "../../../include/IComponent.hpp"
#include <vector>
#include <fstream>
#include <iostream>

namespace nts {

    Comp_2716::Comp_2716() {
        _memory.resize(2048);
        for (auto& byte : _memory) {
            byte.fill(nts::Undefined);
        }
        _outputBuffer.fill(nts::Undefined);
        
        std::ifstream file("rom.bin", std::ios::binary);
        if (file.is_open()) {
            char buffer[2048];
            file.read(buffer, 2048);
            std::streamsize bytesRead = file.gcount();
            for (int i = 0; i < bytesRead; ++i) {
                unsigned char c = static_cast<unsigned char>(buffer[i]);
                for (int bit = 0; bit < 8; ++bit) {
                    _memory[i][bit] = ((c >> bit) & 1) ? nts::True : nts::False;
                }
            }
        }
    }

    int Comp_2716::getAddress() {
        int address = 0;
        static const std::vector<size_t> addrPins = {8, 7, 6, 5, 4, 3, 2, 1, 23, 22, 19};
        
        for (std::size_t i = 0; i < addrPins.size(); ++i) {
            nts::Tristate val = getLinkValue(addrPins[i]);
            if (val == nts::Undefined)
                val = nts::False; 
                
            if (val == nts::True)
                address += (1 << i);
        }
        return address;
    }

    void Comp_2716::simulate(std::size_t tick) {
        (void)tick;
        nts::Tristate ce = getLinkValue(18);
        nts::Tristate oe = getLinkValue(20);

        if (ce == nts::False && oe == nts::False) {
            int addr = getAddress();
            if (addr >= 0 && addr < 2048) {
                _outputBuffer = _memory[addr];
            } else {
                _outputBuffer.fill(nts::Undefined);
            }
        } else {
            _outputBuffer.fill(nts::Undefined);
        }
    }

    nts::Tristate Comp_2716::compute(std::size_t pin) {
        static const std::vector<size_t> dataPins = {9, 10, 11, 13, 14, 15, 16, 17};

        for (size_t i = 0; i < dataPins.size(); ++i) {
            if (dataPins[i] == pin)
                return _outputBuffer[i];
        }
        return nts::Undefined;
    }
}