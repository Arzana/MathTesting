#pragma once

namespace DeJong
{
#define RIGHT_HAND
//#define LEFT_HAND

#if defined(RIGHT_HAND) && defined(LEFT_HAND)
#error Cannot define right and left handed coordinate system!
#endif
#if !defined(RIGHT_HAND) && !defined(LEFT_HAND)
#error Must define either a right or left handed coordinate system!
#endif
}