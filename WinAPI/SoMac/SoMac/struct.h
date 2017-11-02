#pragma once
#include "define.h"
typedef struct _tagFPoint
{
	float x;
	float y;
	_tagFPoint operator +(const _tagFPoint& _other)
	{
		return _tagFPoint{ x + _other.x, y + _other.y };
	}
	_tagFPoint operator -(const _tagFPoint& _other)
	{
		return _tagFPoint{ x - _other.x, y - _other.y };
	}
	_tagFPoint operator *(const _tagFPoint& _other)
	{
		return _tagFPoint{ x * _other.x, y * _other.y };
	}
	_tagFPoint operator /(const _tagFPoint& _other)
	{
		return _tagFPoint{ x / _other.x, y / _other.y };
	}


}tPoint;



typedef struct _tagCollision
{
	OBJ_TYPE left;
	OBJ_TYPE right;
}tColPair;