#include "InputSystem.h"

nc::InputSystem::eKeystate nc::InputSystem::GetKeyState(int id)
{
	eKeystate state = eKeystate::Idle;

	bool keyDown = IsKeyDown(id);
	bool prevKeyDown = IsPreviousKeyDown(id);

	if (keyDown)
	{
		state = (prevKeyDown) ? eKeystate::Held : eKeystate::Pressed;
	}
	else
	{
		state = (prevKeyDown) ?  eKeystate::Release : eKeystate::Idle;

	}
	return state;
}

bool nc::InputSystem::IsKeyDown(int id)
{
	return keyboardState[id];
}

bool nc::InputSystem::IsPreviousKeyDown(int id)
{
	return prevKeyboardState[id];
}

nc::InputSystem::eKeystate nc::InputSystem::GetButtonState(int id)
{
	eKeystate state = eKeystate::Idle;

	bool keyDown = isButtonDown(id);
	bool prevKeyDown = isPreviousButtonDown(id);

	if (keyDown)
	{
		state = (prevKeyDown) ? eKeystate::Held : eKeystate::Pressed;
	}
	else
	{
		state = (prevKeyDown) ? eKeystate::Release : eKeystate::Idle;

	}
	return state;
}

void nc::InputSystem::Startup()
{
	const Uint8* keyboardStateSDL = SDL_GetKeyboardState(&numKeys);
	keyboardState.resize(numKeys);
	std::copy(keyboardStateSDL, keyboardStateSDL + numKeys, keyboardState.begin());
	prevKeyboardState = keyboardState;
}

void nc::InputSystem::Shutdown()
{
}

void nc::InputSystem::Update(float dt)
{
	prevKeyboardState = keyboardState;
	const Uint8* keyboardStateSDL = SDL_GetKeyboardState(nullptr);
	std::copy(keyboardStateSDL, keyboardStateSDL + numKeys, keyboardState.begin());

	prevMouseButtonState = mouseButtonState;
	int x, y;
	Uint32 buttons = SDL_GetMouseState(&x,&y);
	mousePosition = glm::vec2{ x,y };
	mouseButtonState[0] = buttons & SDL_BUTTON_LMASK; //buttons [0000] & [0RML]
	mouseButtonState[1] = buttons & SDL_BUTTON_MMASK; //buttons [0000] & [0RML]
	mouseButtonState[2] = buttons & SDL_BUTTON_RMASK; //buttons [0000] & [0RML]
}
