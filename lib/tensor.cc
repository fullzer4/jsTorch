#include <node_api.h>
#include <torch/torch.h>
#include <iostream>

napi_value init(napi_env env, napi_value exports){
    napi_value findprimes;

    torch::Tensor tensor = torch::rand({2, 3});
    std::cout << tensor << std::endl;
    
    return findprimes;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init);
