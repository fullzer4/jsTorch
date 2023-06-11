#include <node/v8.h>
#include <node/node.h>
#include <torch/torch.h>

namespace Tensors {
  using v8::FunctionCallbackInfo;
  using v8::Isolate; 
  using v8::Local;
  using v8::Object;
  using v8::Number;
  using v8::Value;
  using v8::Exception;
  using v8::String;

 void Tensor(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    if (args.Length() < 1) {
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "É necessário pelo menos um argumento para criar o tensor.")));
      return;
    }

  }
}
