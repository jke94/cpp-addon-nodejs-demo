#include <string>

namespace demoaddon
{
    class Goodbye
    {
    private:
        /* data */
    public:
        Goodbye();
        ~Goodbye();
        std::string sayGoodbye(std::string name);
    };
}