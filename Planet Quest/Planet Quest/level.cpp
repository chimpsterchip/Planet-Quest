// Library Includes

// Local Includes
#include <vector>
#include "Game.h"
#include "utils.h"
#include "backbuffer.h"
#include "framecounter.h"
#include "scene.h"
#include "sprite.h"
#include "resource.h"
#include "Level.h"

// This Include


// Static Variables

// Static Function Prototypes

// Implementation

CLevel::CLevel()
	:m_pScenes(0)
	, m_fpsCounter(0)
{
	
}

CLevel::~CLevel()
{
	delete m_fpsCounter;
	m_fpsCounter = 0;

	if (m_pScenes != 0)
	{
		delete[] m_pScenes;
		m_pScenes = 0;
	}

}

bool
CLevel::Initialise(int _iWidth, int _iHeight, int _iNumScenes)
{
	m_iNumScenes = _iNumScenes;
	m_pScenes = new CScene[m_iNumScenes];

	std::vector<CSprite*> vSprites;
	CSprite* bkgSprite = new CSprite();
	bkgSprite->Initialise(IDB_BITMAP2, IDB_BITMAP3);
	bkgSprite->SetX(400);
	bkgSprite->SetY(300);

	vSprites.push_back(bkgSprite);

	CScene cNewScene = CScene();
	cNewScene.Initialise(1, vSprites);
	m_pScenes[0] = cNewScene;
	return false;
}

void
CLevel::Draw()
{
	m_pScenes->Draw();
	
	//Draw other stuff

    //DrawScore();
	//DrawFPS();
}

void
CLevel::Process(float _fDeltaTick)
{
	//Other processes

	m_fpsCounter->CountFramesPerSecond(_fDeltaTick);
}

void
CLevel::DrawScore()
{
    HDC hdc = CGame::GetInstance().GetBackBuffer()->GetBFDC();

    const int kiX = 0;
    const int kiY = m_iHeight - 14;
	SetBkMode(hdc, TRANSPARENT);
    
    TextOutA(hdc, kiX, kiY, m_strScore.c_str(), static_cast<int>(m_strScore.size()));
}

void 
CLevel::DrawFPS()
{
	HDC hdc = CGame::GetInstance().GetBackBuffer()->GetBFDC(); 

	m_fpsCounter->DrawFPSText(hdc, m_iWidth, m_iHeight);

}
