#ifndef TRX_WRITELINE_H
#define TRX_WRITELINE_H

#include <string>
#include <iostream>

namespace trx
{
    static inline void WriteLine(std::string message)
    {
        std::cout << message << std::endl;
    }
}

#endif