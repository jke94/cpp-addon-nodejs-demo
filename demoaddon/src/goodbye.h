#include <string>

namespace demoaddon
{
    class IGoodbye
    {
        public:
            virtual std::string sayGoodbye(std::string name) = 0;
    };

    class Goodbye : public IGoodbye
    {
    private:
        /* data */
    public:
        Goodbye();
        ~Goodbye();
        std::string sayGoodbye(std::string name) override;
    };
}