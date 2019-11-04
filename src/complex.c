#define NAPI_VERSION 5
#include <node_api.h>

napi_status CplxDestruct(napi_env env, napi_value arr, int* r1, int* r2) {
  napi_status status;
  napi_value r1_value, r2_value;

  status = napi_get_element(env, arr, 0, &r1_value);
  if (status != napi_ok) return status;
  status = napi_get_value_int32(env, r1_value, r1);
  if (status != napi_ok) return status;
  status = napi_get_element(env, arr, 1, &r2_value);
  if (status != napi_ok) return status;
  status = napi_get_value_int32(env, r2_value, r2);
  if (status != napi_ok) return status;

  return napi_ok;
}

napi_status CplxDestructArgv2(napi_env env, napi_callback_info info, int* r1, int* i1, int* r2, int* i2) {
  napi_status status;

  size_t argc = 2;
  napi_value argv[argc];
  status = napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to get callback info");

  status = CplxDestruct(env, argv[0], r1, i1);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to destruct the first complex number");
  status = CplxDestruct(env, argv[1], r2, i2);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to destruct the second complex number");

  return napi_ok;
}

napi_status CplxConstruct(napi_env env, int rational, int imaginary, napi_value* arr) {
  napi_status status;
  napi_value rational_value, imaginary_value;

  status = napi_create_int32(env, rational, &rational_value);
  if (status != napi_ok) return status;
  status = napi_create_int32(env, imaginary, &imaginary_value);
  if (status != napi_ok) return status;

  // Create returning array
  status = napi_create_array(env, arr);
  if (status != napi_ok) return status;

  // Set values
  status = napi_set_element(env, *arr, 0, rational_value);
  if (status != napi_ok) return status;
  status = napi_set_element(env, *arr, 1, imaginary_value);
  if (status != napi_ok) return status;

  return napi_ok;
}

napi_value CplxAdd(napi_env env, napi_callback_info info) {
  napi_status status;

  int r1 = 0, i1 = 0;
  int r2 = 0, i2 = 0;
  status = CplxDestructArgv2(env, info, &r1, &i1, &r2, &i2);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to destruct input parameters");

  // Do calculation
  int rational = r1 + r2;
  int imaginary = i1 + i2;

  napi_value arr;
  status = CplxConstruct(env, rational, imaginary, &arr);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to construct output array");

  return arr;
}

napi_value CplxMultiply(napi_env env, napi_callback_info info) {
  napi_status status;

  int r1 = 0, i1 = 0;
  int r2 = 0, i2 = 0;
  status = CplxDestructArgv2(env, info, &r1, &i1, &r2, &i2);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to destruct input parameters");

  // Do calculation
  int rational = r1 * r2 - i1 * i2;
  int imaginary = r1 * i2 + r2 * i1;

  napi_value arr;
  status = CplxConstruct(env, rational, imaginary, &arr);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to construct output array");

  return arr;
}

napi_status BindFunc(napi_env env, napi_value exports, const char* name, napi_callback cb) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, NULL, NAPI_AUTO_LENGTH, cb, NULL, &fn);
  if (status != napi_ok) return status;

  status = napi_set_named_property(env, exports, name, fn);
  if (status != napi_ok) return status;

  return napi_ok;
}

napi_value Init(napi_env env, napi_value exports) {
  napi_status status;

  status = BindFunc(env, exports, "add", CplxAdd);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to bind add function");

  status = BindFunc(env, exports, "multiply", CplxMultiply);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to bind multiply function");

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
