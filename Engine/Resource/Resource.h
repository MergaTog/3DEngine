#pragma once
#include <iostream>

namespace nc
{
	class Resource
	{
	public:
		virtual bool Load(const std::string& filename, void* data = nullptr) = 0;
	};
}