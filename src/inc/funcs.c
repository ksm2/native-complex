#define GET_INT32(from, target) \
  status = napi_get_value_int32(env, from, target); \
  if (status != napi_ok) return status;

napi_status cplx_bind_func(napi_env env, napi_value exports, const char* name, napi_callback cb) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, NULL, NAPI_AUTO_LENGTH, cb, NULL, &fn);
  if (status != napi_ok) return status;

  status = napi_set_named_property(env, exports, name, fn);
  if (status != napi_ok) return status;

  return napi_ok;
}

napi_status cplx_destruct_argv1(napi_env env, napi_callback_info info, int* r1, int* i1) {
  napi_status status;

  size_t argc = 2;
  napi_value argv[argc];
  status = napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to get callback info");

  GET_INT32(argv[0], r1);
  GET_INT32(argv[1], i1);

  return napi_ok;
}

napi_value cplx_argv1(napi_env env, napi_callback_info info, void (*calculate)(int, int, int*, int*)) {
  napi_status status;

  int r1 = 0, i1 = 0;
  status = cplx_destruct_argv1(env, info, &r1, &i1);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to destruct input parameters");

  // Do calculation
  int real = 0, imaginary = 0;
  calculate(r1, i1, &real, &imaginary);

  napi_value arr;
  status = cplx_construct(env, real, imaginary, &arr);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to construct output array");

  return arr;
}

napi_status cplx_destruct_argv2(napi_env env, napi_callback_info info, int* r1, int* i1, int* r2, int* i2) {
  napi_status status;

  size_t argc = 4;
  napi_value argv[argc];
  status = napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to get callback info");

  GET_INT32(argv[0], r1);
  GET_INT32(argv[1], i1);
  GET_INT32(argv[2], r2);
  GET_INT32(argv[3], i2);

  return napi_ok;
}

napi_value cplx_argv2(napi_env env, napi_callback_info info, void (*calculate)(int, int, int, int, int*, int*)) {
  napi_status status;

  int r1 = 0, i1 = 0, r2 = 0, i2 = 0;
  status = cplx_destruct_argv2(env, info, &r1, &i1, &r2, &i2);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to destruct input parameters");

  // Do calculation
  int real = 0, imaginary = 0;
  calculate(r1, i1, r2, i2, &real, &imaginary);

  napi_value arr;
  status = cplx_construct(env, real, imaginary, &arr);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to construct output array");

  return arr;
}
