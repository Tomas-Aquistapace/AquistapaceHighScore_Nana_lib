#pragma once
#ifndef SCORE_CONTROL_H
#define SCORE_CONTROL_H

#include <iostream>
#include <list>
#include "Score.h"

using namespace std;

class ScoreControl
{
private:
	list<HighScore> ListScore;
	list<HighScore>::iterator iter;
public:
	ScoreControl();
	void newScore(float _Sco);
	void newScore(string _Name, float _Sco);
	void newScore(string _Name, float _Sco, bool _MaxScore, bool _NegativeScore, float _MaxSco);
	HighScore getScoreId(string _Neme);
	void PrintScoreList();
};

#endif // !1