#pragma once
#include "Resource/Resource.h"
#include "Math/MathTypes.h"
#include <math.h>
#include "SDL.h"

namespace nc
{
	class Texture : public Resource
	{
	public:
		Texture() {}
		Texture(class Renderer* renderer);

		bool Create(SDL_Surface* surface);

		bool Load(const std::string& name, void* data) override;

		glm::vec2 GetSize() const;

		friend class Renderer;

	private:
		SDL_Texture* texture{ nullptr };
		SDL_Renderer* renderer{ nullptr };
	};



}