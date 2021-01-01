#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>
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

int kbhit(void)
{
    int ch = getch();

    if (ch != ERR)
    {
        ungetch(ch);
        return 1;
    }
    else
    {
        return 0;
    }
}

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;

    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
}

void Draw()
{
    clear();

    for (int i = 0; i <= width + 1; ++i)
        printw("#");
    printw("\n");

    for (int i = 1; i <= height; ++i)
    {
        for (int j = 0; j <= width + 1; ++j)
        {
            if (j == 0 || j == width + 1)
            {
                printw("#");
            }
            else if (i == y && j == x)
                printw("O");
            else if (i == fruitY && j == fruitX)
                printw("F");
            else
                printw(" ");
        }
        printw("\n");
    }

    for (int i = 0; i <= width + 1; ++i)
        printw("#");
    printw("\n");
}

void Input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 97:
            printw("LEFT");
            dir = LEFT;
            break;
        case 100:
            printw("RIGHT");
            dir = RIGHT;
            break;
        case 119:
            printw("UP");
            dir = UP;
            break;
        case 115:
            printw("DOWN");
            dir = DOWN;
            break;
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        getch();
    }

    // Clear the input line.
}
void Logic()
{
    // switch (dir):
    //     case STOP:
    //         break;
}

int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        refresh();
        sleep(1);
    }
}