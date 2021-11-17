#include "AudioChannel.h"

bool nc::AudioChannel::IsPlaying()
{
	if (channel == nullptr) return false;

	bool isPlaying;
	channel->isPlaying(&isPlaying);


	return isPlaying;
}

void nc::AudioChannel::Stop()
{
	if (IsPlaying())
	{
	channel->stop();

	}
}

void nc::AudioChannel::setPitch(float pitch)
{
	if (IsPlaying())
	{
		channel->setPitch(pitch);
	}
}

float nc::AudioChannel::getPitch()
{
	float pitch = 0;
	if (IsPlaying())
	{
		channel->getPitch(&pitch);
	}
	return pitch;
}

void nc::AudioChannel::setVolume(float volume)
{
	if (IsPlaying())
	{
		channel->setVolume(volume);
	}
}

float nc::AudioChannel::getVolume()
{
	float volume = 0.0f;
	if (IsPlaying())
	{
		channel->getVolume(&volume);
	}
	return volume;
}
