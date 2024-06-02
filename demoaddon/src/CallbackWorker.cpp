#include "CallbackWorker.h"

#include <thread>
#include <chrono>

CallbackWorker::CallbackWorker(Napi::Function &callback)
: Napi::AsyncWorker(callback)
{

}

void CallbackWorker::Execute()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    result = 42;
}

void CallbackWorker::OnOK()
{
    Napi::HandleScope scope(Env());
    
    Callback()
    .Call(
        {
            Env().Null(), Napi::Number::New(Env(), result)
        }
    );    
}
