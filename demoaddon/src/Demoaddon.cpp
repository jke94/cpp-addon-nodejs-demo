#include <napi.h>
#include <memory>
#include <ctime>
#include <string>

#include "Demoaddon.h"
#include "Goodbye.h"
#include "Greeting.h"
#include "CallbackWorker.h"
#include "MessageWorker.h"

namespace demoaddon 
{
    NODE_API_MODULE(addon, Init);

    Napi::Object Init(Napi::Env env, Napi::Object exports) 
    {
        exports.Set(
            Napi::String::New(env, "createObject"),
            Napi::Function::New(env, CreateObject)
        );
        exports.Set(
            Napi::String::New(env, "sayHello"),
            Napi::Function::New(env, SayHello)
        );
        exports.Set(
            Napi::String::New(env, "sayGoodbye"),
            Napi::Function::New(env, SayGoodbye)
        );
        exports.Set(
            Napi::String::New(env, "myPropertyStr"),
            Napi::String::New(env, "TheValueOfTheProperty")
        );
        exports.Set(
            Napi::String::New(env, "myPropertyNumber"),
            Napi::Number::New(env, 1994)
        );
        exports.Set(
            Napi::String::New(env, "startAsyncWork"),
            Napi::Function::New(env, StartAsyncWork)
        );
        exports.Set(
            Napi::String::New(env, "startAsyncWorker"), 
            Napi::Function::New(env, StartAsyncWorker)
        );

        return exports;
    }

    Napi::Object SayGoodbye(const Napi::CallbackInfo& info) 
    {
        std::shared_ptr<IGoodbye> goodbye = std::make_shared<Goodbye>();

        Napi::Env env = info.Env();
        Napi::Object obj = Napi::Object::New(env);

        obj.Set(
            Napi::String::New( env, "msg"),         // Property name.
            goodbye->sayGoodbye(info[0].ToString()) // Property value.
        );

        return obj;
    }

    Napi::Object SayHello(const Napi::CallbackInfo& info) 
    {
        std::shared_ptr<IGreeting> greeting = std::make_shared<Greeting>();

        Napi::Env env = info.Env();
        Napi::Object obj = Napi::Object::New(env);

        obj.Set(
            Napi::String::New(env, "msg"),          // Property name.
            greeting->sayHello(info[0].ToString())  // Property value.
        );

        return obj;
    }

    Napi::Object CreateObject(const Napi::CallbackInfo& info) 
    {
        Napi::Env env = info.Env();
        Napi::Object obj = Napi::Object::New(env);

        // A. Create property 'content' and assign value.

        obj.Set(
            Napi::String::New(env, "content"), 
            info[0].ToString()
        );

        // B.Create property 'created_at' and assign value.

        std::time_t result = std::time(nullptr);
        std::string date_value = std::asctime(std::localtime(&result));

        obj.Set(
            Napi::String::New(env, "created_time"), 
            date_value
        ); 

        return obj;
    }

    Napi::Value StartAsyncWork(const Napi::CallbackInfo& info)
    {
        Napi::Env env = info.Env();

        if (info.Length() < 1 || !info[0].IsFunction()) 
        {
            Napi::TypeError::New(
                env, "Expected a callback function"
            ).ThrowAsJavaScriptException();
            return env.Null();
        }

        Napi::Function callback = info[0].As<Napi::Function>();
        CallbackWorker* worker = new CallbackWorker(callback);
        worker->Queue();
        return env.Undefined();
    }

    Napi::Value StartAsyncWorker(const Napi::CallbackInfo& info)
    {
        Napi::Env env = info.Env();

        if (info.Length() < 2 || !info[0].IsFunction() || !info[1].IsFunction()) 
        {
            Napi::TypeError::New(
                env, "Expected two callback functions"
            ).ThrowAsJavaScriptException();
            
            return env.Null();
        }

        Napi::Function callback = info[0].As<Napi::Function>();
        Napi::Function progressCallback = info[1].As<Napi::Function>();
        MessageWorker* worker = new MessageWorker(callback, progressCallback);
        worker->Queue();
        
        return env.Undefined();
    }    
}
