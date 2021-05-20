// hello.cc using N-API
#include <node_api.h>
#include <iostream>

napi_value Method(napi_env env, napi_callback_info args)
{
  napi_value greeting;
  napi_status status;
  std::cout << env << std::endl;
  status = napi_create_string_utf8(env, "word", NAPI_AUTO_LENGTH, &greeting);
  if (status != napi_ok)
    return nullptr;
  return greeting;
}

/**
 * @brief 初始化函数
 * 
 * @param env 
 * @param exports 
 * @return napi_value 
 */
napi_value init(napi_env env, napi_value exports)
{
  napi_status status;
  napi_value fn;

  // 创建函数fn，从Method转义
  status = napi_create_function(env, nullptr, 0, Method, nullptr, &fn);
  if (status != napi_ok)
    return nullptr;

  // 添加hello函数，函数体为fn
  status = napi_set_named_property(env, exports, "hello", fn);
  if (status != napi_ok)
  {
    return nullptr;
  }

  return exports;
}

// 后面不能添加分号，不是一个函数
// node-gyp构建时使用 NODE_GYP_MODULE_NAME 宏来定义module名称
NAPI_MODULE(NODE_GYP_MODULE_NAME, init)