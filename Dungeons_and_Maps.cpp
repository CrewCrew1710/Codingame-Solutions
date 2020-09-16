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
    cell(int x, int y, char t) : x(x), y(y), type(t) {}
};

int main()
{
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    int startRow;
    int startCol;
    cin >> startRow >> startCol; cin.ignore();
    int n;
    cin >> n; cin.ignore();

    int best = 1000;
    string map = "";
    for (int i = 0; i < n; i++) {
        vector<cell*> grid;
        for (int j = 0; j < h; j++) {
            string mapRow;
            getline(cin, mapRow);
            for (int cols = 0; cols < w; cols++) {
                grid.push_back(new cell(cols, j, mapRow[cols]));
            }
        }
        cell* current = grid[startRow * w + startCol];
        cell* start = current;
        int count = 0;
        bool notpossible = false;
        do {
            //cerr << current->type << endl << endl;
            switch (current->type) {
            case '>':
                if (grid[current->y * w + (current->x + 1)]->type != '#' && grid[current->y * w + (current->x + 1)]->type != '.') { current = grid[current->y * w + (current->x + 1)]; count++; }
                else notpossible = true;
                break;
            case '^':
                if (grid[(current->y - 1) * w + (current->x)]->type != '#' && grid[(current->y - 1) * w + (current->x)]->type != '.') { current = grid[(current->y - 1) * w + (current->x)]; count++; }
                else notpossible = true;
                break;
            case '<':
                if (grid[current->y * w + (current->x - 1)]->type != '#' && grid[current->y * w + (current->x - 1)]->type != '.') { current = grid[current->y * w + (current->x - 1)]; count++; }
                else notpossible = true;
                break;
            case 'v':
                if (grid[(current->y + 1) * w + (current->x)]->type != '#' && grid[(current->y + 1) * w + (current->x)]->type != '.') { current = grid[(current->y + 1) * w + (current->x)]; count++; }
                else notpossible = true;
                break;
            }
        } while (current->type != 'T' && !notpossible && current != start);
        //cerr << count << best << endl;
        if (current == start) map = "TRAP";
        if (notpossible == false) {
            if (count < best) { best = count; map = to_string(i); }
        }
        else {
            if (best == 1000) {
                map = "TRAP";
            }
        }

        //cerr << endl << endl;
    }

    cout << map << endl;


}