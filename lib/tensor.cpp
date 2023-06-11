#include <node/v8.h>
#include <node/node.h>
#include <torch/torch.h>

namespace jstorch {
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

    Local<Value> arg = args[0];
    torch::Tensor tensor;

    if (arg->IsArray()) {
      Local<Array> array = Local<Array>::Cast(arg);
      int64_t size = array->Length();

      tensor = torch::zeros({size});
      for (int64_t i = 0; i < size; i++) {
        Local<Value> element = array->Get(i);
        if (!element->IsNumber()) {
          isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "O array deve conter apenas números.")));
          return;
        }
        double value = element->NumberValue();
        tensor[i] = value;
      }
    } else if (arg->IsObject()) {
      Local<Object> obj = Local<Object>::Cast(arg);
      int64_t size = obj->GetPropertyNames()->Length();

      tensor = torch::zeros({size});
      for (int64_t i = 0; i < size; i++) {
        Local<Value> key = obj->GetProperty(i);
        Local<Value> value = obj->Get(key);
        if (!value->IsNumber()) {
          isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "As propriedades do objeto devem conter apenas números.")));
          return;
        }
        double numValue = value->NumberValue();
        tensor[i] = numValue;
      }
    } else {
      isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "O argumento deve ser um array ou um objeto.")));
      return;
    }
  
    args.GetReturnValue().Set(/* Converter o tensor para um tipo JavaScript*/);
  }

  void Net(const FunctionCallbackInfo<Value>&args){
    Isolate* isolate = args.GetIsolate();

    struct Net : torch::nn::Module {
      Net() {
        // tratar numero de camadas e de neuronios
      }

      torch::Tensor forward(torch::Tensor x) {
        // tratar funcoes da rede
        return x;
      }
    };
  }
}
