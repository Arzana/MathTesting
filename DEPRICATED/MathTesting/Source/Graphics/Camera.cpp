#include "Graphics\Camera.h"
#include "Core\Math.h"

Camera::Camera(float aspr)
	: Camera(aspr, PI2, 5000)
{}

Camera::Camera(float aspr, float fov, float renderDist)
	: Camera(aspr, fov, renderDist, Vector3(0, 0, 50))
{}

Camera::Camera(float aspr, float fov, float renderDist, Vector3 startPos)
	: Camera(aspr, fov, renderDist, startPos, 25, CameraModes::Chase)
{}

Camera::Camera(float aspr, float fov, float renderDist, Vector3 startPos, float boundRadius, CameraModes startMode)
	: Yaw(0), Pitch(0), Roll(0), Speed(0.2f),
	view(Matrix4::Identity), rot(Matrix4::Identity), Projection(Matrix4::Frustrum(fov, aspr, 0.5f, renderDist)),
	pos(startPos), desiredPos(startPos), target(), Offset(0, 10, -10),
	boundRad(boundRad), Mode(startMode)
{}

void Camera::Move(Vector3 vloc)
{
	pos += Speed * vloc;
}

void Camera::Teleport(Vector3 newPos)
{
	pos = newPos;
}

void Camera::Update(Matrix4 target)
{
	//HandleInput();
	UpdateView(target);
}

void Camera::UpdateView(Matrix4 target)
{
	switch (Mode)
	{
		case CameraModes::Free:
			rot.Normalize();
			this->target = pos + rot.GetForward();
			
			rot *= Matrix4::Rotation(rot.GetRight(), Pitch);
			rot *= Matrix4::Rotation(rot.GetUp(), Yaw);
			rot *= Matrix4::Rotation(rot.GetForward(), Roll);

			Yaw = 0;
			Pitch = 0;
			Roll = 0;
			break;
		case CameraModes::Chase:
			rot = Matrix4::Rotation(normalize(rot.GetForward()), Roll);
			this->target = target.GetTranslation();
			this->target += target.GetUp() * Pitch;

			desiredPos = toVector3(target * Offset);
			pos = smoothStep(pos, desiredPos, .15f);
			break;
	}
}