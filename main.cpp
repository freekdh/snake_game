#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <vector>
#include <string.h>
using namespace std;
bool gameOver;

const int width = 25;
const int height = 25;

int x, y, fruitX, fruitY, score;
std::vector<int> x_vec, y_vec;

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
    x_vec.push_back(x);
    y_vec.push_back(y);
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
            dir = LEFT;
            break;
        case 100:
            dir = RIGHT;
            break;
        case 119:
            dir = UP;
            break;
        case 115:
            dir = DOWN;
            break;
        }
    }
    for (int i = 0; i < 10; ++i)
    {
        getch();
    }
}
void Logic()
{
    switch (dir)
    {
    case STOP:
        break;
    case LEFT:
        x -= 1;
        x_vec.insert(x_vec.begin(), x - 1);
        x_vec.pop_back();
        break;
    case RIGHT:
        x += 1;
        x_vec.insert(x_vec.begin(), x + 1);
        x_vec.pop_back();
        break;
    case UP:
        y -= 1;
        y_vec.insert(y_vec.begin(), y - 1);
        y_vec.pop_back();
        break;
    case DOWN:
        y += 1;
        y_vec.insert(y_vec.begin(), y + 1);
        y_vec.pop_back();
        break;
    }

    if (x == 0 || x == width + 1 || y == 0 || y == height + 1)
        gameOver = true;
    if (x == fruitX && y == fruitY)
    {
        score += 1;
        fruitX = rand() % width;
        fruitY = rand() % height;
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
        refresh();
        usleep(100000);
    }
    clear();
    printf("Game Over. Score = %d", score);
}