#include <PluginSDK.h>
#include "Plugin.hpp"
#include <iostream>
Onset::IServerPlugin* Onset::Plugin::_instance = nullptr;


EXPORT(int) OnPluginStart()
{
	// initialize plugin singleton
	Plugin::Get();

	Onset::Plugin::Get()->Log("Loaded Socket Library");
	return 1;
}

EXPORT(void) OnPackageLoad(const char* PackageName, lua_State* L)
{
	
	for (auto const& f : Plugin::Get()->GetFunctions())
		Lua::RegisterPluginFunction(L, std::get<0>(f), std::get<1>(f));
}

EXPORT(int) OnPluginGetApiVersion() {
	return 1;
}

EXPORT(void) OnPluginCreateInterface(Onset::IBaseInterface* PluginInterface)
{
	Onset::Plugin::Init(PluginInterface);
}

EXPORT(void) OnPluginStop()
{
	Onset::Plugin::Get()->Log("unloaded Socket Library");
}
