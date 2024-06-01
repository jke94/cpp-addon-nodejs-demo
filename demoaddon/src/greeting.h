#include <string>

namespace demoaddon
{
    class IGreeting
    {
        public:
            virtual std::string sayHello(std::string name) = 0;
    };

    class Greeting : public IGreeting
    {
        private:
            /* data */
        public:
            Greeting();
            ~Greeting();
            std::string sayHello(std::string name) override;
    };
}