#define NAPI_VERSION 5
#include <node_api.h>
#include "./inc/structs.c"
#include "./inc/funcs.c"
#include "./inc/arithmetics.c"


#define EXPORT(exp, fn) \
  napi_value cb_ ## fn(napi_env env, napi_callback_info info) { \
    return cplx_argv2(env, info, fn); \
  } \
  status = cplx_bind_func(env, exports, exp, cb_ ## fn ); \
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to bind " #exp " function");


napi_value cplx_init(napi_env env, napi_value exports) {
  napi_status status;

  EXPORT("add", add)
  EXPORT("subtract", subtract)
  EXPORT("multiply", multiply)

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, cplx_init)
