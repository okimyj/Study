#pragma once
extern HWND g_hWnd;		// 실제 선언은 main.cpp.

#define WINSIZE_X 1024
#define WINSIZE_Y 768


						// 컴파일 전에 해당 문장을 그대로 코드안에 넣어주는 것.
#define SINGLE(T) public:\
								static T* GetInst() { static T t; return &t;}\
							private:\
								T(); ~T();

#define KEY(key, state) CKeyMgr::GetInst()->GetKeyState(key, state)
#define DT CTimeMgr::GetInst()->DeltaTime()

#define SAFE_DEL(p) if (NULL != p) delete p; p = NULL;
#define SAFE_DEL_ARR(p) if (NULL != p) delete[] p; p = NULL;

#define SAFE_DEL_MAP(key, value, _map) \
	map<key, value>::iterator iter = _map.begin();\
	for(iter; iter != _map.end(); ++iter){SAFE_DEL(iter->second);}

#define SAFE_DEL_LIST(type, _list)\
	list<type>::iterator iter = _list.begin();\
	for(iter; iter != _list.end(); ++iter){SAFE_DEL(*iter);}

#define SAFE_DEL_VEC(type, _vec)\
	vector<type>::iterator iter = _vec.begin();\
	for(iter; iter!=_vec.end(); ++iter){SAFE_DEL(*iter);}


#define DISTANCE(a, b) sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));

#define RADIAN(a, b) acos((a.x-b.x)/(sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2))));

enum SCENE_TYPE
{
	SCENE_LOGO,				// show logo.
	SCENE_READY,				// select character.
	SCENE_GAME,				// ingame.
	SCENE_MAP_TOOL,
	SCENE_END,
};

enum OBJ_TYPE
{
	OBJ_UI,
	OBJ_TILE,
	OBJ_PLAYER,			// player 와 연관된 것들. 
	OBJ_PLAYER_BULLET,
	OBJ_MONSTER,
	OBJ_MONSTER_BULLET,
	OBJ_END,
};

enum COLLIDER_TYPE
{
	COL_CIRCLE,
	COL_RECT,
	COL_END,
};

enum class PLAYER_STATE 
{
	IDLE,
	WALK,
	RUN,
	END,
};
