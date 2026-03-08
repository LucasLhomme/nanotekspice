/*
** EPITECH PROJECT, 2026
** NANO-1
** File description:
** Logger Implementation Fixed
*/

#include "components/Special/Logger.hpp"
#include <iostream>

namespace nts {

    /**
     * \brief Initialize the Logger and open the log file for appending.
     */
    Logger::Logger() : _previousClock(nts::Undefined)
    {
        _file.open("./log.bin", std::ios::out | std::ios::app | std::ios::binary);
    }

    /**
     * \brief Destructor closes the log file if it is open.
     */
    Logger::~Logger()
    {
        if (_file.is_open())
            _file.close();
    }

    /**
     * \brief On clock rising edge, write the 8-bit value to the log file when enabled.
     *
     * @param tick Simulation tick (unused).
     */
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

    /**
     * \brief Logger does not provide readable outputs; always returns Undefined.
     *
     * @param pin Pin number (ignored).
     * @return Undefined
     */
    nts::Tristate Logger::compute(std::size_t pin)
    {
        (void)pin;
        return nts::Undefined;
    }
}