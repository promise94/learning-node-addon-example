// hello.cc using N-API
#include <node_api.h>
#include <iostream>

napi_value Method(napi_env env, napi_callback_info args)
{
  napi_value greeting;
  napi_status status;
  std::cout << *env << std::endl;
  status = napi_create_string_utf8(env, "word", NAPI_AUTO_LENGTH, &greeting);
  if (status != napi_ok)
    return nullptr;
  return greeting;
}

napi_value init(napi_env env, napi_value exports)
{
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, nullptr, 0, Method, nullptr, &fn);
  if (status != napi_ok)
    return nullptr;

  status = napi_set_named_property(env, exports, "hello", fn);
  if (status != napi_ok)
  {
    return nullptr;
  }

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)