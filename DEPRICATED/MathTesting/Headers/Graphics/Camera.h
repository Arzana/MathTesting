#pragma once
#include "Core\Matrix4.h"

enum class CameraModes
{
	None,
	Free,
	Chase
};

struct Camera
{
public:
	CameraModes Mode;
	float Yaw;
	float Pitch;
	float Roll;
	float Speed;
	const Vector3 Offset;
	const Matrix4 Projection;

	Camera(float aspr);
	Camera(float aspr, float fov, float renderDist);
	Camera(float aspr, float fov, float renderDist, Vector3 startPos);
	Camera(float aspr, float fov, float renderDist, Vector3 startPos, float boundRadius, CameraModes startMode);

	void Move(Vector3 vloc);
	void Teleport(Vector3 newPos);
	void Update(Matrix4 target);

	inline Vector3 GetPosition(void) const
	{
		return pos;
	}
	inline Vector3 GetTarget(void) const
	{
		return target;
	}
	inline Matrix4 GetView(void) const
	{
		return view;
	}
	inline Matrix4 GetRotation(void) const
	{
		return rot;
	}
	inline float GetBoundingRadius(void) const
	{
		return boundRad;
	}

private:
	Vector3 pos;
	Vector3 desiredPos;
	Vector3 target;
	Matrix4 view;
	Matrix4 rot;
	float boundRad;

	void HandleInput(void);
	void UpdateView(Matrix4 target);
};