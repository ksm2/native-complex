napi_value cplx_add(napi_env env, napi_callback_info info) {
  napi_status status;

  int r1 = 0, i1 = 0, r2 = 0, i2 = 0;
  status = cplx_destruct_argv2(env, info, &r1, &i1, &r2, &i2);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to destruct input parameters");

  // Do calculation
  int real = r1 + r2;
  int imaginary = i1 + i2;

  napi_value arr;
  status = cplx_construct(env, real, imaginary, &arr);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to construct output array");

  return arr;
}

napi_value cplx_multiply(napi_env env, napi_callback_info info) {
  napi_status status;

  int r1 = 0, i1 = 0, r2 = 0, i2 = 0;
  status = cplx_destruct_argv2(env, info, &r1, &i1, &r2, &i2);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to destruct input parameters");

  // Do calculation
  int real = r1 * r2 - i1 * i2;
  int imaginary = r1 * i2 + r2 * i1;

  napi_value arr;
  status = cplx_construct(env, real, imaginary, &arr);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to construct output array");

  return arr;
}
