#include <string>

namespace demoaddon
{
    class Greeting
    {
    private:
        /* data */
    public:
        Greeting();
        ~Greeting();
        std::string sayHello(std::string name);
    };
}