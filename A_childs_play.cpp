#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


struct cell {
    int x, y;
    char type;
    cell(int x, int y, char type) :x(x), y(y), type(type) {};
};

int main()
{
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    long long n;
    cin >> n; cin.ignore();
    vector<cell*> grid;
    for (int rows = 0; rows < h; rows++) {
        string line;
        getline(cin, line);
        for (int cols = 0; cols < line.size(); cols++) {
            grid.push_back(new cell(cols, rows, line[cols]));
        }
    }

    int dir = 0; //dir 0 -> up 1->right 2->down 3->left
    cell* start = nullptr;
    cell* current = nullptr;
    for (auto const g : grid) {
        if (g->type == 'O') { start = g; current = g; break; }
    }
    int count = 0;
    do {
        switch (dir) {
        case 0:
            if (grid[(current->y - 1) * w + current->x]->type != '#') {
                current->type = '.';
                current = grid[(current->y - 1) * w + current->x];
                current->type = 'O';
                count++;
            }
            else { dir = 1; }
            break;
        case 1:
            if (grid[current->y * w + (current->x + 1)]->type != '#') {
                current->type = '.';
                current = grid[(current->y) * w + (current->x + 1)];
                current->type = 'O';
                count++;
            }
            else { dir = 2; }
            break;
        case 2:
            if (grid[(current->y + 1) * w + current->x]->type != '#') {
                current->type = '.';
                current = grid[(current->y + 1) * w + current->x];
                current->type = 'O';
                count++;
            }
            else { dir = 3; }
            break;
        case 3:
            if (grid[current->y * w + (current->x - 1)]->type != '#') {
                current->type = '.';
                current = grid[current->y * w + (current->x - 1)];
                current->type = 'O';
                count++;
            }
            else { dir = 0; }
            break;
        }
    } while (current != start && n > count);

    n = n % count;

    while (n > 0) {
        switch (dir) {
        case 0:
            if (grid[(current->y - 1) * w + current->x]->type != '#') {
                current->type = '.';
                current = grid[(current->y - 1) * w + current->x];
                current->type = 'O';
                n--;
            }
            else { dir = 1; }
            break;
        case 1:
            if (grid[current->y * w + (current->x + 1)]->type != '#') {
                current->type = '.';
                current = grid[(current->y) * w + (current->x + 1)];
                current->type = 'O';
                n--;
            }
            else { dir = 2; }
            break;
        case 2:
            if (grid[(current->y + 1) * w + current->x]->type != '#') {
                current->type = '.';
                current = grid[(current->y + 1) * w + current->x];
                current->type = 'O';
                n--;
            }
            else { dir = 3; }
            break;
        case 3:
            if (grid[current->y * w + (current->x - 1)]->type != '#') {
                current->type = '.';
                current = grid[current->y * w + (current->x - 1)];
                current->type = 'O';
                n--;
            }
            else { dir = 0; }
            break;
        }
    }
    cout << current->x << ' ' << current->y << endl;
    delete[] current;
    delete[] start;
}