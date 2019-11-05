// Destructs a JS tuple into real and imaginary ints
napi_status cplx_destruct(napi_env env, napi_value arr, int* real, int* imaginary) {
  napi_status status;
  napi_value real_value, imaginary_value;

  status = napi_get_element(env, arr, 0, &real_value);
  if (status != napi_ok) return status;
  status = napi_get_value_int32(env, real_value, real);
  if (status != napi_ok) return status;
  status = napi_get_element(env, arr, 1, &imaginary_value);
  if (status != napi_ok) return status;
  status = napi_get_value_int32(env, imaginary_value, imaginary);
  if (status != napi_ok) return status;

  return napi_ok;
}

// Constructs a JS tuple from real and imaginary ints
napi_status cplx_construct(napi_env env, int real, int imaginary, napi_value* arr) {
  napi_status status;
  napi_value real_value, imaginary_value;

  status = napi_create_int32(env, real, &real_value);
  if (status != napi_ok) return status;
  status = napi_create_int32(env, imaginary, &imaginary_value);
  if (status != napi_ok) return status;

  // Create returning array
  status = napi_create_array(env, arr);
  if (status != napi_ok) return status;

  // Set values
  status = napi_set_element(env, *arr, 0, real_value);
  if (status != napi_ok) return status;
  status = napi_set_element(env, *arr, 1, imaginary_value);
  if (status != napi_ok) return status;

  return napi_ok;
}
