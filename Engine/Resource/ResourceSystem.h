#pragma once
#include <map>
#include "Resource.h"
#include "Framework/System.h"
#include <string>
#include <memory>
#include <algorithm>

namespace nc
{
	class ResourceSystem : public System
	{
	public:
		void Add(const std::string& name, std::shared_ptr<nc::Resource> resource);

		void Startup() override {}
		void Shutdown() override {}
		void Update(float dt) override {}

		template <typename T>
		std::shared_ptr<T> Get(const std::string& name, void* data = nullptr);

		template <typename T>
		std::vector<std::shared_ptr<T>> Get();

	private:
		std::map<std::string, std::shared_ptr<Resource>> resources;
	};

	template <typename T>
	inline std::shared_ptr<T> ResourceSystem::Get(const std::string& name, void* data)
	{
		if (resources.find(string_tolower(name)) != resources.end())
		{
			//To Lower to make filename easier
			return std::dynamic_pointer_cast<T>(resources[string_tolower(name)]);
		}
		else
		{
			std::shared_ptr resource = std::make_shared<T>();
			resource->Load(string_tolower(name), data);
			resources[string_tolower(name)] = resource;

			return resource;
		}
	}

	template <typename T>
	inline std::vector<std::shared_ptr<T>> ResourceSystem::Get()
	{
		std::vector<std::shared_ptr<T>> result;
		for (auto& element : resources)
		{
			if (dynamic_cast<T*>(element.second.get()))
			{
				result.push_back(std::dynamic_pointer_cast<T>(element.second));
			}
		}
		return result;
	}

	inline void ResourceSystem::Add(const std::string& name, std::shared_ptr<nc::Resource> resource)
	{
		resources[name] = resource;
	}
}