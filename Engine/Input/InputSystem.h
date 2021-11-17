#pragma once
#include "Framework/System.h"
#include <vector>
#include "SDL.h"
#include <iostream>
#include "Math/MathTypes.h"
#include <array>

namespace nc
{
	class InputSystem : public System
	{
	public:
		enum class eKeystate { Idle, Pressed, Held, Release };
		enum class eMouseButton
		{
			Left,
			Middle, 
			Right
		};

		eKeystate GetKeyState(int id);
		bool IsKeyDown (int id);
		bool IsPreviousKeyDown (int id);

		const glm::vec2& GetMousePosition() { return mousePosition; }

		bool isButtonDown(int id) { return mouseButtonState[id];  }
		bool isPreviousButtonDown(int id) { return prevMouseButtonState[id];  }
		eKeystate GetButtonState(int id);

	public:
		// Inherited via System
		virtual void Startup() override;
		virtual void Shutdown() override;
		virtual void Update(float dt) override;


	private:
		std::vector<Uint8> keyboardState;
		std::vector<Uint8> prevKeyboardState;
		int numKeys;

		glm::vec2 mousePosition;
		std::array<Uint8, 3>mouseButtonState;
		std::array<Uint8, 3>prevMouseButtonState;

	};


}