#include "Graphics\Animations\SpriteAnimation.h"

Animation::Animation(std::initializer_list<Sprite2*> frames)
	: current(0), max(frames.size()), loop(false), running(false), delta(0)
{
}

Animation::~Animation(void)
{}

bool Animation::NextFrame(void)
{
	return false;
}

bool Animation::PreviousFrame(void)
{
	return false;
}

void Animation::Start(bool loop, float interval)
{}

void Animation::Stop(void)
{}

void Animation::Reset(void)
{}

void Animation::Update(float dt)
{}
