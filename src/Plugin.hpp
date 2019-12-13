#pragma once
#include "Singleton.hpp"

#include <PluginSDK.h>
#include <vector>
#include <tuple>
#include <functional>


class Plugin : public Singleton<Plugin>
{
	friend class Singleton<Plugin>;
private:
	Plugin();
	~Plugin() = default;

	using FuncInfo_t = std::tuple<const char*, lua_CFunction>;
	std::vector<FuncInfo_t> _func_list;

	inline void Define(const char* name, lua_CFunction func)
	{
		_func_list.emplace_back(name, func);
	}

public:
	decltype(_func_list) const & GetFunctions() const
	{
		return _func_list;
	}
};