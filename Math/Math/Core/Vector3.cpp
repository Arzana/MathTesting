#include "Vector3.h"

using namespace DeJong;

const Vector3 Vector3::Zero = Vector3();
const Vector3 Vector3::UnitX = Vector3(1, 0, 0);
const Vector3 Vector3::UnitY = Vector3(0, 1, 0);
const Vector3 Vector3::UnitZ = Vector3(0, 0, 1);
const Vector3 Vector3::One = Vector3(1);
const Vector3 Vector3::Right = Vector3(1, 0, 0);
const Vector3 Vector3::Left = Vector3(-1, 0, 0);
const Vector3 Vector3::Up = Vector3(0, 1, 0);
const Vector3 Vector3::Down = Vector3(0, -1, 0);
#if defined(RIGHT_HAND)
const Vector3 Vector3::Backward = Vector3(0, 0, 1);
const Vector3 Vector3::Forward = Vector3(0, 0, -1);
#endif
#if defined (LEFT_HAND)
const Vector3 Vector3::Forward = Vector3(0, 0, 1);
const Vector3 Vector3::Backward = Vector3(0, 0, -1);
#endif