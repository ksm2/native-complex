#define NAPI_VERSION 5
#include <node_api.h>
#include "./inc/structs.c"
#include "./inc/funcs.c"
#include "./inc/arithmetics.c"

napi_value cplx_init(napi_env env, napi_value exports) {
  napi_status status;

  status = cplx_bind_func(env, exports, "add", cplx_add);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to bind add function");

  status = cplx_bind_func(env, exports, "subtract", cplx_subtract);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to bind subtract function");

  status = cplx_bind_func(env, exports, "multiply", cplx_multiply);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to bind multiply function");

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, cplx_init)
