#pragma once

#define REGISTER_CLASS(class) nc::ObjectFactory::Instance().Register<class>(#class);
#define CREATE_ENGINE_OBJECT(class) nc::ObjectFactory::Instance().Create<nc::class>(#class);

#include <vector>
#include <memory>
#include <algorithm>
#include "Audio/AudioSystem.h"

//Framework
#include "Framework/EventSystem.h"
#include "Framework/Singleton.h"
#include "Framework/Factory.h"

//core
#include "Core/Utils.h"
#include "Core/FileSystem.h"
#include "Input/InputSystem.h"
#include "Core/Timer.h"
#include "Core/Json.h"
#include "Core/Serializable.h"



//Math
#include "Math/Random.h"
#include "Math/MathUtils.h"
#include "Math/Transform.h"
#include "Math/MathTypes.h"

//Graphics
#include "Graphics/Renderer.h"
#include "Graphics/Texture.h"
#include "Graphics/Shader.h"
#include "Graphics/Program.h"
#include "Graphics/Material.h"
#include "Graphics/VertexBuffer.h"



#include "Object/Actor.h"
#include "Object/Scene.h"

#include "Component/PhysicsComponent.h"
#include "Component/AudioComponent.h"
#include "Component/CameraComponent.h"
#include "Component/MeshComponent.h"
#include "Component/ModelComponent.h"
#include "Component/LightComponent.h"


#include "Component/FreeCameraController.h"


#include "Resource/ResourceSystem.h"


namespace nc
{
	using ObjectFactory = Singleton<Factory<std::string, Object>>;


	class Engine
	{
	public:
		void Startup();

		void Shutdown();

		void Update();
		void Draw(Renderer* renderer);

		template<typename T>
		T* Get();

	public:
		FrameTimer time;

	private:
		std::vector<std::unique_ptr<System>> systems;
	};
	template<typename T>
	inline T* Engine::Get()
	{
		for (auto& system : systems)
		{
			if (dynamic_cast<T*>(system.get())) return dynamic_cast<T*>(system.get());
		}

		return nullptr;
	}
}