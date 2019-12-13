#include <PluginSDK.h>


void callEvent(lua_State *L, const char* hookName, const char* response) {
	    lua_getglobal(L, "CallEvent");
	    lua_pushstring(L, hookName);
	    lua_pushstring(L, response);
	    int error = lua_pcall(L, 2, 0,0);
	    if (error)
	    {
            Onset::Plugin::Get()->Log("[Socket Library] Error on call event!");
	    }

}
void callEvent(lua_State *L, const char* hookName, int sock) {
    lua_getglobal(L, "CallEvent");
    lua_pushstring(L, hookName);
    lua_pushnumber(L, sock);
    int error = lua_pcall(L, 2, 0,0);
    if (error)
    {
        Onset::Plugin::Get()->Log("[Socket Library] Error on call event!");
    }

}