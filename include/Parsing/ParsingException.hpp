/*
** EPITECH PROJECT, 2026
** parsingexception
** File description:
** exception handle for parsing
*/

#ifndef _PARSINGEXCEPTION_HPP_
#define _PARSINGEXCEPTION_HPP_

#include <exception>
#include <iostream>

namespace nts {
    class ParsingException : public std::exception {
        
        public:
            explicit ParsingException(const std::string message);
            const char *what() const noexcept override;
    
        private:
            std::string _message;
    };
}

#endif