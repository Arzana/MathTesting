#pragma once
#include <initializer_list>
#include "Graphics\Sprite2.h"

struct Animation
{
public:
	Animation(std::initializer_list<Sprite2*> frames);
	Animation(const Animation& other) = delete;
	~Animation(void);

	Animation& operator=(const Animation& other) = delete;

	bool NextFrame(void);
	bool PreviousFrame(void);
	void Start(bool loop, float interval);
	void Stop(void);
	void Reset(void);
	void Update(float dt);
	
	inline const Sprite2* GetSprite(void) const
	{
		return frames + current;
	}

private:
	Sprite2 *frames;
	size_t current;
	size_t max;
	bool loop;
	bool running;
	float delta;
};