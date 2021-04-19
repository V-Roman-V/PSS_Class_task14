#include "passchecker.h"

void PassChecker::checkSize(const std::string& pass) noexcept(false)
{
    if(pass.size() < MIN_PASS_SIZE)
        throw TooShortPassword();
}

void PassChecker::checkCase(const std::string& pass) noexcept(false)
{
    if(pass.find_first_of( "ABCDEFGHIJKLMNOPQRSTYVWXYZ") == std::string::npos)
        throw AllInLowerCase();
}

void PassChecker::checkChar(const std::string& pass) noexcept(false)
{
    if(pass.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTYVWXYZ0123456789") == std::string::npos)
        throw NoSpecialCharacters();
}

void PassChecker::checkPass(const std::string& pass) noexcept
{
    try {
        checkSize(pass);
        checkCase(pass);
        checkChar(pass);
        std::cout<<"The password is strong."<<std::endl;
    } catch (const TooShortPassword&) {
        std::cout<<"The password is too short. Use at least "<<MIN_PASS_SIZE<<" characters."<<std::endl;
    } catch (const AllInLowerCase&) {
        std::cout<<"The password is in lowercase. Use at least one character in uppercase."<<std::endl;
    } catch (const NoSpecialCharacters&) {
        std::cout<<"The password does not contain special characters. Use at least one of them."<<std::endl;
    }
}
