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
	void operator +=(const _tagFPoint& _other)
	{
		x += _other.x;
		y += _other.y;
	}
	_tagFPoint operator -(const _tagFPoint& _other)
	{
		return _tagFPoint{ x - _other.x, y - _other.y };
	}
	void operator -=(const _tagFPoint& _other)
	{
		x -= _other.x;
		y -= _other.y;
	}
	_tagFPoint operator *(const _tagFPoint& _other)
	{
		return _tagFPoint{ x * _other.x, y * _other.y };
	}
	void operator *=(const _tagFPoint& _other)
	{
		x *= _other.x;
		y *= _other.y;
	}
	_tagFPoint operator *(float _value)
	{
		return _tagFPoint{ x * _value, y * _value };
	}
	_tagFPoint operator *=(float _value)
	{
		x *= _value;
		y *= _value;
	}

	_tagFPoint operator /(const _tagFPoint& _other)
	{
		return _tagFPoint{ x / _other.x, y / _other.y };
	}
	void operator /=(const _tagFPoint& _other)
	{
		x /= _other.x;
		y /= _other.y;
	}
	_tagFPoint operator /(float _value)
	{
		return _tagFPoint{ x / _value, y / _value };
	}
	_tagFPoint operator /=(float _value)
	{
		x /= _value;
		y /= _value;
	}
	_tagFPoint operator =(const POINT& _other)
	{
		x = (float)_other.x;
		y = (float)_other.y;
		return _tagFPoint{x, y};
	}
	bool operator ==(const _tagFPoint& _other)
	{
		return (x == _other.x && y == _other.y);
	}
	bool operator != (const _tagFPoint& _other)
	{
		return !(x == _other.x && y == _other.y);
	}
}tPoint;



typedef struct _tagCollision
{
	OBJ_TYPE left;
	OBJ_TYPE right;
}tColPair;
class CTexture;
typedef struct _tagAnimFrame
{
	CTexture*	m_pTexture;		// 참조하는 텍스쳐	
	tPoint		m_ptStartPos;	// 텍스쳐에서 참조하는 위치(픽셀)
	tPoint		m_ptCropSize;	// Crop Size
	int				m_iDir;				// 이미지 참조 방향
	float			m_fInteval;		// 해당 이미지 유지 시간	
}tFrame;