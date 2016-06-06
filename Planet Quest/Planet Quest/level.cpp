// Library Includes

// Local Includes
#include "Game.h"
#include "utils.h"
#include "backbuffer.h"
#include "framecounter.h"
#include "background.h"
#include "sprite.h"
#include "resource.h"

// This Include
#include "Level.h"

// Static Variables

// Static Function Prototypes

// Implementation

CLevel::CLevel()
	:m_fpsCounter(0)
	, m_pBackground(0)
{
	m_pBackground = new CBackGround();
}

CLevel::~CLevel()
{
	delete m_fpsCounter;
	m_fpsCounter = 0;

	delete m_pBackground;
	m_pBackground = 0;

}

bool
CLevel::Initialise(int _iWidth, int _iHeight)
{
	CSprite* bkgSprite = new CSprite();
	bkgSprite->Initialise(IDB_BITMAP2, IDB_BITMAP3);
	bkgSprite->SetX(400);
	bkgSprite->SetY(300);
	m_pBackground = new CBackGround();
	VALIDATE(m_pBackground->Initialise(bkgSprite));
	return false;
}

void
CLevel::Draw()
{
	m_pBackground->Draw();
	
	//Draw other stuff

    //DrawScore();
	//DrawFPS();
}

void
CLevel::Process(float _fDeltaTick)
{
	m_pBackground->Process(_fDeltaTick);

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
