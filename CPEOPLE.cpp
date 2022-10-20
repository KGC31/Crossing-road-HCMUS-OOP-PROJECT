#include"CPEOPLE.h"
#include"Graphics.h"

const string people[] = { " o ", R"(/|\)", R"(/ \)" };


void CPEOPLE::DRAW_PEOPLE(int mX, int mY){
	for (int i = 0; i < 3; i++) {
		Controller::GotoXY(mX, mY + i);
		cout << people[i];
	}
}

void CPEOPLE::Delete(int mX, int mY) {
	for (int i = 0; i < 3; i++) {
		Controller::GotoXY(mX, mY + i);
		cout << "   ";
	}
}

void CPEOPLE::Up(int& mY) {
	if (mY == 4)
		return;
	mY -= 4;
}

void CPEOPLE::Left(int& mX) {
	if (mX == 6)
		return;
	mX -= 2;
}

void CPEOPLE::Right(int& mX) {
	if (mX + 3 == 69)
		return;
	mX += 2;
}

void CPEOPLE::Down(int& mY) {

	if (mY + 3 == 27)
		return;
	mY += 4;
}

/*
bool isImpact(const CVEHICLE*& vehicle);
bool isImpact(const CANIMAL*& animal) {

}
bool isFinish();
*/
void CPEOPLE::mainPeople() {
	CPEOPLE p;
	int x = p.getPosX(), y = p.getPosY();
	while (p.isDead()) {
		p.DRAW_PEOPLE(p.getPosX(), p.getPosY());
		switch (Controller::GetConsoleInput()) {
		case 2:
		{
			p.Delete(x, y);
			p.Up(y);
			break;
		}
		case 3:
		{
			p.Delete(x, y);
			p.Left(x);
			break;
		}
		case 4:
		{
			p.Delete(x, y);
			p.Right(x);
			break;
		}
		case 5:
		{
			p.Delete(x, y);
			p.Down(y);
			break;
		}
		}
		p.updatePos(x, y);
	}
}