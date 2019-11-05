#define NAPI_VERSION 5
#include <node_api.h>
#include <math.h>
#include "./inc/structs.c"
#include "./inc/funcs.c"
#include "./inc/arithmetics.c"

#define BIND(fn) \
  status = cplx_bind_func(env, exports, #fn, cb_ ## fn ); \
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to bind " #fn " function");

#define EXPORT1(fn) \
  napi_value cb_ ## fn(napi_env env, napi_callback_info info) { \
    return cplx_argv1(env, info, fn); \
  } \
  BIND(fn)

#define EXPORT2(fn) \
  napi_value cb_ ## fn(napi_env env, napi_callback_info info) { \
    return cplx_argv2(env, info, fn); \
  } \
  BIND(fn)


napi_value cplx_init(napi_env env, napi_value exports) {
  napi_status status;

  EXPORT2(add)
  EXPORT2(subtract)
  EXPORT2(multiply)
  EXPORT2(divide)
  EXPORT1(absolute)
  EXPORT1(conjugate)

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, cplx_init)
