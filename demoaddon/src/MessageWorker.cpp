#include "MessageWorker.h"

#include <thread>
#include <chrono>
#include <vector>


MessageWorker::MessageWorker( 
    Napi::Function &callback, 
    Napi::Function &progressCallback
) : 
    Napi::AsyncProgressWorker<char>(callback), 
    progressCallback(Napi::Persistent(progressCallback)
) 
{

}

void MessageWorker::Execute(const Napi::AsyncProgressWorker<char>::ExecutionProgress& progress)
{
    for (int i = 0; i < 5; ++i) 
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::string message = "Message " + std::to_string(i + 1);
        progress.Send(message.c_str(), message.size());
    }    
}

void MessageWorker::OnProgress(const char *data, size_t size)
{
    Napi::HandleScope scope(Env());
    progressCallback.Call({Napi::String::New(Env(), data, size)});
}

void MessageWorker::OnOK()
{
    Napi::HandleScope scope(Env());
    Callback().Call({Env().Null()});    
}
