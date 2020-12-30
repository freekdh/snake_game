#include <iostream>
#include <unistd.h>
using namespace std;
bool gameOver;

const int width = 20;
const int height = 20;

int x, y, fruitX, fruitY, score;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
}
void Draw()
{
    system("clear");

    for (int i = 0; i <= width + 1; ++i)
        cout << "#";
    cout << endl;

    for (int i = 1; i <= height; ++i)
    {
        for (int j = 0; j <= width + 1; ++j)
        {
            if (j == 0 || j == width + 1)
            {
                cout << "#";
            }
            else if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
                cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i <= width + 1; ++i)
        cout << "#";
    cout << endl;
}
void Input()
{
}
void Logic()
{
}

int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        sleep(1);
    }
}