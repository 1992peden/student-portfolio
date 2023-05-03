#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;//Global var goes here
const int width = 20;
const int height = 20;//Map dimensions
int x, y, fruitX, fruitY, score;//head position, fruit position, score
int tailX[100], tailY[100];
int nTail;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;//Create a data type called eDirection, store the eDirection in the variable dir

void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;//Initial head position, halfway in the width and halfway in the height
	fruitX = rand() % width;
	fruitY = rand() % height;//Randomize position of the fruit to be eaten
	score = 0;
}
void Draw() {

	system("cls");//sends a command to the system to clear the screen (windows, in the console window)
	for (int i = 0; i < width+1; i++)//Print a border for the top wall
		cout << '#';
	cout << endl;

	for (int i = 0; i < height; i++) //This loop prints the rest of the map
	{
		for (int j = 0; j < width; j++) 
		{
			if (j == 0)//print a border on the left side
				cout << '#';
			if (i == y && j == x)//Loop runs for each spot on the map. If the spot matches the x,y, of the head, print O.
				cout << 'O';
			else if (i == fruitY && j == fruitX)//Loop runs for each spot. If the spot matches the x,y, of the fruit, print F.
				cout << 'F';
			else 
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i) 
					{
						cout << 'o';
						print = true;
					}
				}
				if (!print)
					cout << ' ';
			}
			if (j == width - 1)
				cout << '#';//Print a border on the right side
		}
		cout << endl;
	}

	for (int i = 0; i < width+1; i++)//Print a border for the bottom wall
		cout << '#';
	cout << endl;
	cout << "\nScore: " << score << endl;

}

void Input() //function to handle controls, conio.h used here
{
	if (_kbhit())//if user inputs from keyboard, run this
	{
		switch (_getch())//switch for the characters pressed on the keyboard
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'w':
			dir = UP;
			break;
		case 'x':
			gameOver = true;//WASD controls, x to exit
			break;
		}
	}
	
}

void Logic() 
{
	int prevX = tailX[0];//Track the preceeding tail segments with these
	int prevY = tailY[0];//
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	
	for (int i = 1; i < nTail; i++)//Run once for each tail segment
	{
		prev2X = tailX[i];//When there is a tail, set the tail2 x and y = tailx and y
		prev2Y = tailY[i];
		tailX[i] = prevX;//Then, set the tail equal to the tail ahead of it
		tailY[i] = prevY;
		prevX = prev2X;//Update tail to the initial tail position
		prevY = prev2Y;
	}

	switch (dir)//switch loop based on dir
	{
	case LEFT:
		x--;//Decrement the x coordinate of the head when LEFT
		break;
	case RIGHT:
		x++;//Increment the x coordinate of the head when RIGHT
		break;
	case UP:
		y--;//Decrement the y coordinate (the row) of the head when UP
		break;
	case DOWN:
		y++;//Increment the y coordinate (the row) of the head when DOWN
		break;//Incrementing y moves down because you're incrementing the row; in the console, this looks like moving to the next time
	}
	/*if (x > width || x < 0 || y > height || y < 0)//gameOver if you go out of bounds, we'll take this out for now
		gameOver = true;*/

	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;

	for (int i = 0; i < nTail; i++) {
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	}

	if (x == fruitX && y == fruitY) {//If the head of the snake touches a fruit, increase score
		score += 10;
		fruitX = rand() % width;//Print a new fruit in a random spot
		fruitY = rand() % height;
		nTail++;//Increase tail size by 1
	}

}

int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(40);//utilizes windows.h to slow down the console so the game becomes playable
	}

	return 0;
}