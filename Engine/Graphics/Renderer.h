#pragma once
#include "Framework/System.h"
#include "Math/Transform.h"

#include "SDL.h"
#include <string>
#include <glad/glad.h>

namespace nc
{
	class Renderer : public System 
	{
	public:
		virtual void Startup() override;
		virtual void Shutdown() override;
		virtual void Update(float dt) override;

		void Create(const std::string& name, int width, int height);
		void BeginFrame();
		void EndFrame();

		friend class Texture;

	private:
		SDL_GLContext context;
		SDL_Window* window{ nullptr };
	};
}