#include <napi.h>

namespace demoaddon 
{
    Napi::Object Init(Napi::Env env, Napi::Object exports);
    
    Napi::Object SayGoodbye(const Napi::CallbackInfo& info);
    Napi::Object SayHello(const Napi::CallbackInfo& info);
    Napi::Object CreateObject(const Napi::CallbackInfo& info);
    Napi::Value StartAsyncWork(const Napi::CallbackInfo& info);
    Napi::Value StartAsyncWorker(const Napi::CallbackInfo& info);
}