#pragma once
#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <string>

using namespace std;

class HighScore
{
public:
	HighScore(float _Sco);
	HighScore(string _Name, float _Sco);
	HighScore(string _Name, float _Sco, bool _MaxScore, bool _NegativeScore, float _MaxSco);
	void setName(string _Name);
	void setSco(float _Sco);
	void setMaxScore(float _MaxSco);
	void plusSco(float Point);
	void lessSco(float Point);
	float getSco();
	string getName();
	float getMaxScore();
private:
	float Sco;
	float MaxSco;
	string Name;
	bool MaxScore;
	bool NegativeScore;
};

#endif // !1