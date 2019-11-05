napi_status cplx_bind_func(napi_env env, napi_value exports, const char* name, napi_callback cb) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, NULL, NAPI_AUTO_LENGTH, cb, NULL, &fn);
  if (status != napi_ok) return status;

  status = napi_set_named_property(env, exports, name, fn);
  if (status != napi_ok) return status;

  return napi_ok;
}

napi_status cplx_destruct_argv2(napi_env env, napi_callback_info info, int* r1, int* i1, int* r2, int* i2) {
  napi_status status;

  size_t argc = 2;
  napi_value argv[argc];
  status = napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to get callback info");

  status = cplx_destruct(env, argv[0], r1, i1);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to destruct the first complex number");
  status = cplx_destruct(env, argv[1], r2, i2);
  if (status != napi_ok) napi_throw_error(env, NULL, "Unable to destruct the second complex number");

  return napi_ok;
}
