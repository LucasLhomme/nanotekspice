/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Logger Implementation
*/

#include "components/Special/Logger.hpp"
#include <iostream>

namespace nts {

    Logger::Logger() : _previousClock(nts::Undefined)
    {
        _file.open("./log.bin", std::ios::out | std::ios::trunc | std::ios::binary);
    }

    Logger::~Logger()
    {
        if (_file.is_open())
            _file.close();
    }

    nts::Tristate Logger::getPinValue(std::size_t pin)
    {
        if (_links.find(pin) == _links.end())
            return nts::Undefined;
        return _links[pin].first->compute(_links[pin].second);
    }

    void Logger::simulate(std::size_t tick)
    {
        (void)tick;
        nts::Tristate clock = getPinValue(9);
        nts::Tristate inhibit = getPinValue(10);
        if (inhibit == nts::True) {
            _previousClock = clock;
            return;
        }
        if (_previousClock == nts::False && clock == nts::True) {
            char c = 0;
            for (std::size_t i = 0; i < 8; ++i) {
                nts::Tristate bit = getPinValue(i + 1);
                if (bit == nts::True)
                    c |= (1 << i);
            }
            if (_file.is_open()) {
                _file.put(c);
                _file.flush();
            }
        }
        _previousClock = clock;
    }

    nts::Tristate Logger::compute(std::size_t pin)
    {
        (void)pin;
        return nts::Undefined;
    }
}