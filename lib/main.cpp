#include <node/v8-local-handle.h>
#include <node/v8.h>
#include <node/node.h>
#include "tensor.cpp"

namespace lib {

  using v8::Local;
  using v8::Object;


  void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "tensor", Tensors::Tensor);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize);
}
