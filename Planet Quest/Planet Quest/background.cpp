// Library Includes

// Local Includes
#include "utils.h"
#include "backbuffer.h"
#include "game.h"

// This Include
#include "background.h"

// Static Variables

// Static Function Prototypes

// Implementation

CBackGround::CBackGround()
{

}

CBackGround::~CBackGround()
{
	delete m_Sprite;
	m_Sprite = nullptr;
}

bool
CBackGround::Initialise(CSprite* _Sprite)
{
	m_Sprite = _Sprite;
	return (true);
}

void
CBackGround::Draw()
{
	m_Sprite->Draw();
	//Draw the background

}

void
CBackGround::Process(float _fDeltaTick)
{
	//Process the background?
}
