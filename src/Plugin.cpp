#include "Plugin.hpp"

#include <string>

#define UNUSED(x) (void) x;

#ifdef LUA_DEFINE
	#undef LUA_DEFINE
#endif

#define LUA_DEFINE(name) Define(#name, [](lua_State *L) -> int

Plugin::Plugin() {

	

}