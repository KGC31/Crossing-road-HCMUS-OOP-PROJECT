#pragma once

#include "CANIMAL.h"
#include "CVEHICLE.h"

class CPEOPLE {
	int mX = 36, mY = 24;
	bool mState = true;		// dead or alive state
public:
	CPEOPLE() {};
	~CPEOPLE() {};
	int getPosX(){
		return mX;
	}
	int getPosY() {
		return mY;
	}
	void updatePos(int x, int y) {
		mX = x;
		mY = y;
	}
	bool isDead() 
	{
		return mState;
	}
	void DRAW_PEOPLE(int mX, int mY); 
	void Delete(int mX, int mY);
	void Up(int& mY);
	void Left(int& mX);
	void Right(int& mX);
	void Down(int& mY);
	bool isImpact(const CVEHICLE*& vehicle);
	bool isImpact(const CANIMAL*& animal);
	bool isFinish();
	static void mainPeople();
};