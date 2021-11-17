#include "Random.h"
#include <random>
#include <limits>

namespace nc
{
	std::default_random_engine g_Engine;



	void SeedRandom(unsigned int seed)
	{
		g_Engine.seed(seed);
	}

	float Random()
	{
		std::uniform_real_distribution<float>distribution{ 0, 1 };
		return distribution(g_Engine);
	}
	float RandomRange(float min, float max)
	{
		std::uniform_real_distribution<float>distribution{ min, max };
		return distribution(g_Engine);
	}

	int RandomInt()
	{
		std::uniform_int_distribution<int>distribution{ 0, std::numeric_limits<int>::max() };
		return distribution(g_Engine);
	}
	int RandomIntMAX(int max)
	{
		std::uniform_int_distribution<int>distribution{ 0, max -1 };
		return distribution(g_Engine);
	}
	int RandomRangeINT(int min, int max)
	{
		std::uniform_int_distribution<int>distribution{ min, max };
		return distribution(g_Engine);
	}
}