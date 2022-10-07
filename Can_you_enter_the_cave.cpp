#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Maze
{
    public:
    int ** maze;
    int y;
    int x;
    const double ratio = 0.7;

    Maze(int y, int x)
    {
        this->maze = new int*[y];
        this->y = y;
        this->x = x;
        for (int i = 0; i < y; i++)
        {
            int * temp = new int[x];
            this->maze[i] = temp; 
        }
    }
    void randomizer()
    {
        srand(time(NULL));
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                maze[i][j] = rand() / (double)RAND_MAX > this->ratio;
            }
        }
    }
    void print()
    {
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                putchar(maze[i][j] + '0');
                putchar(' ');
            }
            putchar('\n');
        }
    }
    void cool_print()
    {
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                switch (this->maze[i][j])
                {
                case 0:std::cout << "  ";break;
                case 1:std::cout << "[]";break;
                default:std::cout<< "  ";break;
                }
            }
            putchar('\n');
        }
    }
    bool solve()
    {
        bool result = false;
        for (int i = 0; i < this->y; i++)
        {
            result = result || solver(0, i, 0);
        }
        return result;
    }
    bool solver(int x = 0, int y = 0, int from = 0)
    {
        if (this->x <= x || this->y <= y || x < 0 || y < 0) return false;
        else if (this->maze[y][x]) return false;
        else if (this->x == x + 1) return true;
        bool result = solver(x + 1, y, 0);
        if (from != -1) result = result || solver(x, y + 1,  1);
        if (from !=  1) result = result || solver(x, y - 1, -1);
        return result;
    }
};

int main()
{
    Maze asd(4,10);
    asd.randomizer();
    asd.print();
    cout << endl << asd.solve() << endl;
    return 0;
}