#ifndef __SCENE_H__
#define __SCENE_H__

#include "sprite.h"
#include <vector>

//A Scenes holds sprites and anything within a scene. Buttons, Quests, NPCs etc
class CScene
{
public:
	CScene();
	~CScene();

	bool Initialise(int _iNumSprites, std::vector<CSprite*> _vSprites);
	void Draw();
private:
	int m_iNumSprites;
	std::vector<CSprite*> m_vSprites;
};

#endif //__SCENE_H__