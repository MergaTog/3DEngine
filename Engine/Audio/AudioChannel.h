#pragma once
#include "fmod.hpp"

namespace nc
{
	class AudioChannel
	{
	public:
		AudioChannel() {}
		AudioChannel(FMOD::Channel* channel) : channel { channel } {}

		bool IsPlaying();
		void Stop();

		void setPitch(float pitch);
		float getPitch();

		void setVolume(float volume);
		float getVolume();


	private:
		FMOD::Channel* channel{ nullptr };
	};
}