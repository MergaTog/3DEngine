#include "Timer.h"

nc::Timer::clock_tick_type nc::Timer::ElapsedTicks()
{
	clock_duration duration = clock::now() - timePoint;
	return duration.count();
}

float nc::Timer::ElapsedSeconds()
{
	return ElapsedTicks() / static_cast<float>(clock_duration::period::den);
}

void nc::FrameTimer::tick()
{
	clock_duration duration = clock::now() - startTimePoint;
	time = duration.count() / static_cast<float>(clock_duration::period::den);

	duration = clock::now() - frameTimePoint;
	deltaTime = duration.count() / static_cast<float>(clock_duration::period::den) * timeScale;

	frameTimePoint = clock::now();
}
