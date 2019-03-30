#include <iostream>

enum class computer {
    SCREEN,
    KEYBOARD,
    TOUCHPAD,
    POWER_ADAPTOR,
};

std::ostream& operator<<(std::ostream& os, const computer &l)
{
    os << static_cast<std::underlying_type<computer>::type>(l);
    return os;
}

int main()
{
    computer laptop_scr = computer::SCREEN;

    switch (laptop_scr) {
        case computer::SCREEN:
            std::cout << "screen" << std::endl;
        break;
        case computer::KEYBOARD:
            std::cout << "keyboard" << std::endl;
        break;
        case computer::TOUCHPAD:
            std::cout << "touchpad" << std::endl;
        break;
        case computer::POWER_ADAPTOR:
            std::cout << "power adaptor" << std::endl;
        break;

    }

    std::cout << "screen is " << laptop_scr << std::endl;
}

