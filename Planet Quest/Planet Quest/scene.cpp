#include "scene.h"

CScene::CScene()
{

}

CScene::~CScene()
{
	
}

bool CScene::Initialise(int _iNumSprites, std::vector<CSprite*> _vSprites)
{
	m_iNumSprites = _iNumSprites;
	m_vSprites = _vSprites;
	return true;
}

void CScene::Draw()
{
	for (int i = 0; i < m_iNumSprites; ++i)
	{
		m_vSprites.at(i)->Draw();
	}
}