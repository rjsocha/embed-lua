#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

const char luaScript[] __attribute__((section("LUAScript"))) = "print('ERROR:MISSING')";

int catch_exit(lua_State *L) {
  int exit_code = luaL_optinteger(L, 1, 0);
  lua_pushinteger(L, exit_code);
  return lua_error(L);
}

int main(int argc, char **argv) {
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);

  // Override the os.exit function with the custom handler
  /*
  lua_getglobal(L, "os");
  lua_pushcfunction(L, catch_exit);
  lua_setfield(L, -2, "exit");
  lua_pop(L, 1);
  */

  lua_newtable(L);
  for (int i = 0; i < argc; i++) {
    lua_pushstring(L, argv[i]);
    lua_rawseti(L, -2, i);
  }
  lua_setglobal(L, "arg");

  int error_code;
  int result = luaL_dostring(L, luaScript);
  if (result == LUA_OK) {
     error_code = lua_tointeger(L, -1);
  } else {
    fprintf(stderr, "Error: %s\n", lua_tostring(L, -1));
    error_code = 255;
  }
  lua_close(L);
  printf("RC: %d\n", error_code);
  return error_code;
}
