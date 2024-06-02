#include <napi.h>

class CallbackWorker : public Napi::AsyncWorker 
{
    private:
        int result;    
    
    public:
        CallbackWorker(Napi::Function& callback);
        void Execute() override;
        void OnOK() override;
};