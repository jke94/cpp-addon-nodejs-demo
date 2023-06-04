#include <napi.h>

#include "goodbye.h"
#include "greeting.h"

namespace demoaddon 
{
    Napi::Object SayGoodbye(const Napi::CallbackInfo& info) 
    {
        Goodbye *goodbye = nullptr;

        Napi::Env env = info.Env();
        Napi::Object obj = Napi::Object::New(env);

        obj.Set(Napi::String::New(
            // Property name.
            env, "msg"),
            // Property value.
            goodbye->sayGoodbye(info[0].ToString()));

        delete goodbye;

        return obj;
    }

    Napi::Object SayHello(const Napi::CallbackInfo& info) 
    {
        Greeting *greeting = nullptr;

        Napi::Env env = info.Env();
        Napi::Object obj = Napi::Object::New(env);

        obj.Set(Napi::String::New(
            // Property name.
            env, "msg"),
            // Property value.
            greeting->sayHello(info[0].ToString()));

        delete greeting;

        return obj;
    }

    Napi::Object CreateObject(const Napi::CallbackInfo& info) 
    {
        Napi::Env env = info.Env();
        Napi::Object obj = Napi::Object::New(env);
        obj.Set(Napi::String::New(env, "msg"), info[0].ToString());

        return obj;
    }

    Napi::Object Init(Napi::Env env, Napi::Object exports) 
    {
        exports.Set(
            // property name => "createObject"
            Napi::String::New(env, "createObject"),

            // property value => 'CreateObject' function.
            Napi::Function::New(env, CreateObject));

        exports.Set(
            Napi::String::New(env, "sayHello"),
            Napi::Function::New(env, SayHello));
        
        exports.Set(
            Napi::String::New(env, "sayGoodbye"),
            Napi::Function::New(env, SayGoodbye));

        exports.Set(
            Napi::String::New(env, "myPropertyStr"),
            Napi::String::New(env, "TheValueOfTheProperty"));

        exports.Set(
            Napi::String::New(env, "myPropertyNumber"),
            Napi::Number::New(env, 1994));

        return exports;
    }

    NODE_API_MODULE(addon, Init)
}
