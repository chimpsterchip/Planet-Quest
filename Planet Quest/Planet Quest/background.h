#pragma once

#if !defined(__BACKGROUND_H__)
#define __BACKGROUND_H__

#include "sprite.h"
// Library Includes

// Local Includes

// Types

// Constants

// Prototypes


class CBackGround
{
	// Member Functions
public:
	CBackGround();
	virtual ~CBackGround();

	virtual bool Initialise(CSprite* _Sprite);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);


protected:

private:
	CBackGround(const CBackGround& _kr);
	CBackGround& operator= (const CBackGround& _kr);

	// Member Variables
public:
	
protected:


private:
	CSprite* m_Sprite;
};

#endif