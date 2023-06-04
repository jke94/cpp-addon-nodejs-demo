#include "greeting.h"

namespace demoaddon
{
    Greeting::Greeting(/* args */)
    {
    }
    
    Greeting::~Greeting()
    {
    }

    std::string Greeting::sayHello(std::string name)
    {
        return "Hello " + name + "!";
    }
}