/**
 * Author Devendra Naga (devendra.aaru@gmail.com)
 *
 * License Apache
 */
#include <iostream>
#include <type_traits>
#include <cstdint>
#include <list>

int main()
{
    struct s {
    };
    typedef struct s s_;

    std::cout <<" type of int fundamental " << (std::is_fundamental<int>::value ? "true" : "false") << std::endl;
    std::cout <<" type of struct fundamental " << (std::is_fundamental<s>::value ? "true" : "false") << std::endl;
    std::cout <<" type of uint32_t fundamental " << (std::is_fundamental<uint32_t>::value ? "true" : "false") << std::endl;
    std::cout <<" type of s_  fundamental " << (std::is_fundamental<s_>::value ? "true" : "false") << std::endl;
}

