#include <napi.h>

class IMessageWorker : public Napi::AsyncProgressWorker<char>
{
    public:
        virtual void Execute(const Napi::AsyncProgressWorker<char>::ExecutionProgress& progress) = 0;
        virtual void OnProgress(const char* data, size_t size) = 0;
        virtual void OnOK() = 0;
};

class MessageWorker : public Napi::AsyncProgressWorker<char>
{
    private:

        Napi::FunctionReference progressCallback;

    public:
  
        MessageWorker(Napi::Function& callback, Napi::Function& progressCallback);

        void Execute(const Napi::AsyncProgressWorker<char>::ExecutionProgress& progress) override;

        void OnProgress(const char* data, size_t size) override;

        void OnOK() override;
};