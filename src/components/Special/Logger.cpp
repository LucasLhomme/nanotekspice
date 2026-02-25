/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Logger Implementation Fixed
*/

#include "components/Special/Logger.hpp"
#include <iostream>

namespace nts {

    Logger::Logger() : _previousClock(nts::Undefined)
    {
        _file.open("./log.bin", std::ios::out | std::ios::app | std::ios::binary);
    }

    Logger::~Logger()
    {
        if (_file.is_open())
            _file.close();
    }

    void Logger::simulate(std::size_t tick)
    {
        (void)tick;
        nts::Tristate clock = getLinkValue(9);
        nts::Tristate inhibit = getLinkValue(10);
        if (inhibit != nts::False) {
            _previousClock = clock;
            return;
        }
        if (_previousClock == nts::False && clock == nts::True) {
            char c = 0;
            for (std::size_t i = 0; i < 8; ++i) {
                nts::Tristate bit = getLinkValue(i + 1);
                if (bit == nts::Undefined) {
                    _previousClock = clock;
                    return;
                }
                if (bit == nts::True)
                    c |= (1 << i);
            }
            if (_file.is_open())
                _file.put(c);
        }
        _previousClock = clock;
    }

    nts::Tristate Logger::compute(std::size_t pin)
    {
        (void)pin;
        return nts::Undefined;
    }
}