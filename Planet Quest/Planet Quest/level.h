#pragma once

#if !defined(__LEVEL_H__)
#define __LEVEL_H__


#include <vector>
#include <string>


class CFPSCounter;
class CBackGround;
class CScene;

//A Level represents a planet and holds scenes.
class CLevel
{
    // Member Functions
public:
    CLevel();
    virtual ~CLevel();

    virtual bool Initialise(int _iWidth, int _iHeight, int _iNumScenes);

    virtual void Draw();
    virtual void Process(float _fDeltaTick);

protected:
    void UpdateScoreText();
    void DrawScore();
	void DrawFPS();

private:
    CLevel(const CLevel& _kr);
    //CLevel& operator= (const CLevel& _kr);

    // Member Variables
public:

protected:
	int m_iNumScenes;
	CScene* m_pScenes;
	CFPSCounter* m_fpsCounter;

    int m_iWidth;
    int m_iHeight;

    std::string m_strScore;

private:

};

#endif    // __LEVEL_H__
