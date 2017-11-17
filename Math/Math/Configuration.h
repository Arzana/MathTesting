#pragma once

namespace DeJong
{
#define RIGHT_HAND
//#define LEFT_HAND
#define COLUMN_MAJOR
//#define ROW_MAJOR
#define TOP_ORIGIN
//#define BOTTOM_ORIGIN

#pragma region CHECKS
#if defined(RIGHT_HAND) && defined(LEFT_HAND)
#error Cannot define right and left handed coordinate system!
#endif
#if !defined(RIGHT_HAND) && !defined(LEFT_HAND)
#error Must define either a right or left handed coordinate system!
#endif

#if defined(COLUMN_MAJOR) && defined(ROW_MAJOR)
#error Cannot define column and row major matrix systems!
#endif
#if !defined(COLUMN_MAJOR) && !defined(ROW_MAJOR)
#error Must define either column or row major matrix system!
#endif

#if defined(TOP_ORIGIN) && defined(BOTTOM_ORIGIN)
#error Cannot define top and bottom as screen origin!
#endif
#if !defined(TOP_ORIGIN) && !defined(BOTTOM_ORIGIN)
#error Must define either top or bottom screen origin!
#endif
#pragma endregion
}