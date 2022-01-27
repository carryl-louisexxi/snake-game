#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;
bool gameover;
const int Mapwidth = 20;
const int Mapheight = 20;
int HeadX, HeadY, FruitX, FruitY, score;
int coloum, row;

enum eDirection
{
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
} dir;

void Setup()
{
	gameover = false;
	HeadX = Mapwidth / 2;
	HeadY = Mapheight / 2;
	FruitX = rand() % Mapwidth;
	FruitY = rand() % Mapheight;
	score = 0;
}

void Draw()
{
	system("cls");
	for (coloum = 0; coloum < Mapwidth + 2; coloum++)
		cout << "#";
	cout << endl;

	for (row = 0; row < Mapheight; row++)
	{
		for (coloum = 0; coloum < Mapwidth; coloum++)
		{
			if (coloum == 0)
				cout << "#";
			if (HeadY == row && HeadX == coloum)
				cout << "O";
			else if (FruitY == row && FruitX == coloum)
				cout << "F";
			else
				cout << " ";
			if (coloum == Mapwidth - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (coloum = 0; coloum < Mapwidth + 2; coloum++)
		cout << "#";
	cout << endl;
	cout << "SCORE= " << score << endl;
}

void Input()
{
	if (_kbhit())
	{
		switch (getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 'x':
			dir = DOWN;
			break;
		}
	}
}

void Logic()
{
	switch (dir)
	{
	case LEFT:
		HeadX--;
		break;
	case RIGHT:
		HeadX++;
		break;
	case UP:
		HeadY--;
		break;
	case DOWN:
		HeadY++;
		break;
	}
	if (HeadX < 0 || HeadX > Mapwidth || HeadY < 0 || HeadY > Mapheight)
		gameover = true;
	if (HeadX == FruitX && HeadY == FruitY)
	{
		score += 10;
		FruitX = rand() % Mapwidth;
		FruitY = rand() % Mapheight;
	}
}

int main()
{
	Setup();
	while (!gameover)
	{
		Draw();
		Input();
		Logic();
	}
}