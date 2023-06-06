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

  void Tensor(const FunctionCallbackInfo<Value>&args){
    Isolate* isolate = args.GetIsolate();


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
 
  void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "tensor", Tensor);
    NODE_SET_METHOD(exprots, "net", Tensor);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize);
}
