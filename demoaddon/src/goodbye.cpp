#include "goodbye.h"

namespace demoaddon
{
    Goodbye::Goodbye(/* args */)
    {
    }
    
    Goodbye::~Goodbye()
    {
    }

    std::string Goodbye::sayGoodbye(std::string name)
    {
        return "Goodbye " + name + "!";
    }
}