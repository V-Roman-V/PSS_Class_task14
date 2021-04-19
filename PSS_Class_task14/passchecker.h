#ifndef PASSWORDCHECKER_H
#define PASSWORDCHECKER_H

#include <string>
#include <iostream>

class PassChecker
{
    static const short int MIN_PASS_SIZE = 5;

    class TooShortPassword: std::exception {};
    class AllInLowerCase: std::exception {};
    class NoSpecialCharacters: std::exception {};

    inline static void checkSize(const std::string& pass) noexcept(false);
    inline static void checkCase(const std::string& pass) noexcept(false);
    inline static void checkChar(const std::string& pass) noexcept(false);

    PassChecker() = delete;
    ~PassChecker() = delete;
    PassChecker operator=(const PassChecker&) = delete;

public:
    static void checkPass(const std::string& pass) noexcept;
};

#endif // PASSWORDCHECKER_H
